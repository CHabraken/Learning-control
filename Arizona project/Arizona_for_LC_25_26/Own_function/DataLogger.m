classdef DataLogger < handle

    properties (Access=public)
        FileName
        NameValuePairs
        TrialParameters
    end
    methods (Access=public)
        function obj = DataLogger()%constructor
            obj.cleanupObj = onCleanup(@() obj.cleanup());
            obj.NameValuePairs = containers.Map('KeyType','char', 'ValueType','any');
            obj.TrialParameters = containers.Map('KeyType','char', 'ValueType','any');
        end
        function delete(obj)%destructor
            obj.cleanup();
        end
        
        %File control
        function FullPath = OpenFile(obj, Folder,FileName)
            if obj.file_id > 0
                error('A file is already open.');
            end

            if ~obj.IsAbsolutePath(Folder)
                Folder = fullfile(pwd, Folder);
            end
            if ~exist(Folder, 'dir')
                mkdir(Folder);
            end
             
            FullPath = fullfile(Folder, FileName);
            new = 0;

            if(~exist(FullPath))
                new = 1;
            end

            obj.file_id = fopen(FullPath,'a'); %Append only. Creates file if needed. Writes at end of file.
            if obj.file_id == -1
               warning('Failed to open file: %s', FullPath);
               FullPath = [];
               return
            end

            if(~new)
                fprintf(obj.file_id,'\n\n\n'); %make space from last measurement
            end
        end
        function CloseFile(obj)
            obj.cleanup();
        end

        %Store Measurement settings
        function SetGeneralParameters(obj, varargin)
            if mod(length(varargin),2) ~= 0
                error('Arguments must be supplied as name-value pairs.');
            end
            
            for k = 1:2:numel(varargin)
                name  = char(string(varargin{k}));
                value = varargin{k+1};

                if isKey(obj.NameValuePairs, name)
                    values = obj.NameValuePairs(name);
                    values{end+1} = value;

                    obj.NameValuePairs(name) = values;
                else
                    obj.NameValuePairs(name) = {value};
                end

            end
        end
        function SetMeasurement(obj, measurement)
            obj.FileName = measurement;
        end
        
        %Store Trial parameters
        function SetTrialParameters(obj, varargin)
            if mod(numel(varargin),2) ~= 0
                error('Arguments must be supplied as name-value pairs.');
            end

            for k = 1:2:numel(varargin)
                name  = char(string(varargin{k}));
                value = varargin{k+1};

                if isKey(obj.TrialParameters, name)
                    values = obj.TrialParameters(name);
                    values{end+1} = value;

                    obj.TrialParameters(name) = values;
                else
                    obj.TrialParameters(name) = {value};
                end

            end

        end
    
        %Write to log file
        function WriteHeader(obj)
            if(obj.file_id == -1)
                warning('file not open, data not logged!');
                return;
            end      
            width = 100;
            fprintf(obj.file_id,'%s\n',repmat('-',1,width));
            if(~isempty(obj.FileName))
                obj.PrintCentered(obj.file_id,sprintf('Measurement : %s', obj.FileName), width);
            end
            obj.PrintCentered(obj.file_id,sprintf('DateTime : %s', datestr(now,'yyyy-mm-dd HH:MM:SS')), width);
            fprintf(obj.file_id,'%s\n',repmat('-',1,width));
            
            fprintf(obj.file_id,'\nGeneral Parameters:\n');
            fprintf(obj.file_id,'----------------------------------\n');

            names = keys(obj.NameValuePairs);
            for k = 1:numel(names)

                name = names{k};
                values = obj.NameValuePairs(name);
                
                fprintf(obj.file_id,'%-20s ', name);

                for n = 1:numel(values)
                    value = values{n};
            
                    if isnumeric(value)
                        fprintf(obj.file_id,'%g', value);
                    else
                        fprintf(obj.file_id,'%s', string(value));
                    end
            
                    if n < numel(values)
                        fprintf(obj.file_id,', ');
                    end
                end
                fprintf(obj.file_id,'\n');
            end
        end
        function WriteTrialData(obj)
            if(obj.file_id == -1)
                warning('file not open, data not logged!');
                return;
            end  
            names = keys(obj.TrialParameters);

            colWidth = max(cellfun(@length,names)) + 4;
            colWidth = max(colWidth,15);

            fprintf(obj.file_id,'\nTrial Data:\n');

            % Header
            for k = 1:numel(names)
                fprintf(obj.file_id,'%-*s', colWidth, names{k});
            end
            fprintf(obj.file_id,'\n');

            % Separator
            fprintf(obj.file_id,'%s\n', ...
                repmat('-',1,colWidth*numel(names)));

            % Determine number of rows
            numRows = 0;
            for k = 1:numel(names)
                values = obj.TrialParameters(names{k});
                numRows = max(numRows,numel(values));
            end

            % Data rows
            for row = 1:numRows

                for col = 1:numel(names)

                    values = obj.TrialParameters(names{col});

                    if row <= numel(values)

                        value = values{row};

                        if isnumeric(value)
                            txt = num2str(value);
                        else
                            txt = char(string(value));
                        end

                    else

                        txt = '';

                    end

                    fprintf(obj.file_id,'%-*s', colWidth, txt);

                end

                fprintf(obj.file_id,'\n');

            end

        end
        function WriteTrialDataAscii(obj)
            if(obj.file_id == -1)
                warning('file not open, data not logged!');
                return;
            end  
            fprintf(obj.file_id,'\nTrial Data:\n');

            colWidth = 20;
            names = keys(obj.TrialParameters);

            % Top border
            fprintf(obj.file_id,'+');
            for k = 1:numel(names)
                fprintf(obj.file_id,'%s+', repmat('-',1,colWidth));
            end
            fprintf(obj.file_id,'\n');

            % Header row
            fprintf(obj.file_id,'|');
            for k = 1:numel(names)
                fprintf(obj.file_id,'%-*s|', colWidth, names{k});
            end
            fprintf(obj.file_id,'\n');

            % Header separator
            fprintf(obj.file_id,'+');
            for k = 1:numel(names)
                fprintf(obj.file_id,'%s+', repmat('-',1,colWidth));
            end
            fprintf(obj.file_id,'\n');

            % Determine number of rows
            numRows = 0;
            for k = 1:numel(names)
                values = obj.TrialParameters(names{k});
                numRows = max(numRows, numel(values));
            end

            % Data rows
            for row = 1:numRows

                fprintf(obj.file_id,'|');

                for col = 1:numel(names)

                    values = obj.TrialParameters(names{col});

                    if row <= numel(values)

                        value = values{row};

                        if isnumeric(value)
                            txt = num2str(value);
                        else
                            txt = char(string(value));
                        end

                    else

                        txt = '';

                    end

                    fprintf(obj.file_id,'%-*s|', colWidth, txt);

                end

                fprintf(obj.file_id,'\n');

            end

            % Bottom border
            fprintf(obj.file_id,'+');
            for k = 1:numel(names)
                fprintf(obj.file_id,'%s+', repmat('-',1,colWidth));
            end
            fprintf(obj.file_id,'\n');
        end
    end

    %member variables
    properties (Access = private)
        file_id = -1
        cleanupObj
    end

    %private functions
    methods (Access = private)
        function cleanup(obj)

            if ~isempty(obj.file_id) && obj.file_id > 0
                fprintf('Closing log file\n');
                fclose(obj.file_id);
                obj.file_id = -1;
            end

        end
    end
    methods (Static,Access=private)
        function tf = IsAbsolutePath(path)

            tf = false;

            if length(path) >= 3
                tf = isletter(path(1)) && ...
                    path(2) == ':' && ...
                    (path(3) == '\' || path(3) == '/');
            end

        end
        function PrintCentered(fid, txt, width)

            pad = max(0, floor((width - length(txt))/2));

            fprintf(fid,'%s%s\n', ...
                repmat(' ',1,pad), txt);

        end
    end

end