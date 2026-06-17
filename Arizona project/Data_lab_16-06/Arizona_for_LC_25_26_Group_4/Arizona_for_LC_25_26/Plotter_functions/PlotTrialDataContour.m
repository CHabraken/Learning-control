function handles = PlotTrialDataContour(history,trial,...
    init,...
    increase_trial,...
    update_f_j,...
    update_f_plus_one,...
    update_r,...
    update_y_e,...
    update_r_y)
%% Description
%PlotTrialdataContour   
% Function with input flags and if/else conditions to plot trail data,
% including contouring measures, for ILC.
% For the cartesian plots, assumes phi = 0!
%
% Author: Johan Kon
% Date:   April 2021

% cell_handles struct stores for each subplot [ax, h_j_min_1, h_j,
% h_j_plus_1]. First three columns of figure are associated with 
% [output, input, error] respectively. Fourth column is norm of input, norm
% of error, and contour error. Last column is cartesian view and
% contour error.
persistent cell_handles hor vert
ref_style = '-';
ref_color = 'k';
f_j_plus_1_style = '-';
f_j_plus_1_color = 'r';
f_j_style = '-';
f_j_color = [0 0 150]/255;
f_j_min_1_style = '-';
f_j_min_1_color = [0 150 0]/255;
e_j_style = f_j_style;
e_j_color = f_j_color;
e_j_min_1_style = f_j_min_1_style;
e_j_min_1_color = f_j_min_1_color;
p_j_style = f_j_style; % y is here general notation for output, not direction y!
p_j_color = f_j_color;
p_j_min_1_style = f_j_min_1_style;
p_j_min_1_color = f_j_min_1_color;
r_y_j_style = f_j_style; % y is here general notation for output, not direction y!
r_y_j_color = f_j_color;
r_y_j_min_1_style = f_j_min_1_style;
r_y_j_min_1_color = f_j_min_1_color;
% todo: 
% entry for color of contour error, now color of error
% colors for 2-norms 
% move these settings to some file?
% configuration for markers
% convert to class and methods and stuff? Is more suitable
%% Startup
if init
    hor = 5; vert = 3; % dimension of subplut
    cell_handles = cell(hor,vert);
    cell_handles(:) = {cell(4,1)};
    
    figTrialData = figure('Name','Trial data','Units','Normalized','Position',[0 0.0250 1 0.9]);
    % First three columns: [output, shaped ref, input, error] of time
    names = {'y','x','\phi'}; % Order is y, x, phi always
    units = {'[m]','[m]','[rad]'};
    for ii = 1:vert
        for jj = 1:4
            id = (ii-1)*hor + jj;
            ax = subplot(vert,hor,id); hold on; grid on; grid minor; 
            h1 = plot(history.t,NaN(history.Nref,1));
            h2 = plot(history.t,NaN(history.Nref,1));
            h3 = plot(history.t,NaN(history.Nref,1));
            xlabel('Time [s]');
            if jj == 1 
                ylabel(['$', names{ii}, '$ ', units{ii}]);
                set(h1,'LineStyle',p_j_min_1_style,'Color',p_j_min_1_color);
                set(h2,'LineStyle',p_j_style,'Color',p_j_color);
                set(h3,'LineStyle',ref_style,'Color',ref_color);
                legend([h1,h2,h3],{['$ ',names{ii},'_{j-1}$'],['$ ',names{ii},'_{j}$'],'$r_{j}$'})
            elseif jj == 2
                ylabel(['$', names{ii}, '$ ', units{ii}]);
                set(h1,'LineStyle',r_y_j_min_1_style,'Color',r_y_j_min_1_color);
                set(h2,'LineStyle',r_y_j_style,'Color',r_y_j_color);
                set(h3,'LineStyle',ref_style,'Color',ref_color);
                legend([h1,h2],{'$r_{y_j}$','$r_{y_{j+1}}$'})
            elseif jj == 3
                ylabel(['$f_', names{ii}, '$ [V]']);
                set(h1,'LineStyle',f_j_min_1_style,'Color',f_j_min_1_color);
                set(h2,'LineStyle',f_j_style,'Color',f_j_color);
                set(h3,'LineStyle',f_j_plus_1_style,'Color',f_j_plus_1_color);
                legend([h1,h2,h3],{'$f_{j-1}$','$f_{j}$','$f_{j+1}$'})
            elseif jj == 4
                ylabel(['$e_', names{ii}, '$ ', units{ii}]);
                set(h1,'LineStyle',e_j_min_1_style,'Color',e_j_min_1_color);
                set(h2,'LineStyle',e_j_style,'Color',e_j_color);
                legend([h1,h2],{'$e_{j-1}$','$e_{j}$'})
            end
            cell_handles{ii,jj}{1} = ax;
            cell_handles{ii,jj}{2} = h1; % serves as var_{j-1} e.g. e_{j-1}
            cell_handles{ii,jj}{3} = h2; % serves as var_{j}, e.g. e_j
            cell_handles{ii,jj}{4} = h3; % Serves as reference for output plot, next input for input plot, inactive for error plot
        end
    end
    
    % Fourth column: two norms of errors
    jj = 5;
    for ii = 1:vert
        id = (ii-1)*hor + jj;
        ax = subplot(vert,hor,id); hold on; grid on; grid minor;
        xlabel('Trial');
        ylabel(['$||e_ ', names{ii}, '||_2$'])
        h_2 = plot(history.trials, NaN(size(history.trials)));
        set(ax,'XTick',history.trials,'YScale','log')
        set(h_2,'LineStyle',e_j_style,'Color',e_j_color,'Marker','o')
        cell_handles{ii,jj}{1} = ax;
        cell_handles{ii,jj}{2} = h_2;
    end
    
%     % Fifth column: contour and shaped reference
%     jj = 6;
% 
%     % First row: (x,y) plot of output and reference
%     ii = 1; id = (ii-1)*hor + jj;
%     ax = subplot(vert,hor,id); hold on; grid on; grid minor;
%     xlabel(['$', names{1}, '$ ', units{1}]);
%     ylabel(['$', names{2}, '$ ', units{2}]);
%     h_j_min_1 = plot3(NaN(size(history.t)),NaN(size(history.t)),history.t);
%     h_j = plot3(NaN(size(history.t)),NaN(size(history.t)),history.t);
%     h_r = plot3(NaN(size(history.t)),NaN(size(history.t)),history.t);
%     set(h_j_min_1,'LineStyle',p_j_min_1_style,'Color',p_j_min_1_color);
%     set(h_j,'LineStyle',p_j_style,'Color',p_j_color);
%     set(h_r,'LineStyle',ref_style,'Color',ref_color);
%     legend([h_j_min_1,h_j,h_r],{'$p_{j-1}$','$p_j$','$r_{j}$'})
%     cell_handles{ii,jj}{1} = ax;
%     cell_handles{ii,jj}{2} = h_j_min_1;
%     cell_handles{ii,jj}{3} = h_j;
%     cell_handles{ii,jj}{4} = h_r;

    % Titles
    subplot(vert,hor,1)
    title('\textbf{Output}')
    subplot(vert,hor,2)
    title('\textbf{Shaped Reference}')
    subplot(vert,hor,3)
    title('\textbf{Input}')
    subplot(vert,hor,4)
    title('\textbf{Error}')
    subplot(vert,hor,5)
    title('\textbf{2-norms of error}')
%     subplot(vert,hor,6)
%     title('\textbf{2D}')


    % Set figure size
    % tightfig(figTrialData); Breaks the legend
    % set(figTrialData,'WindowState','maximized')
end

%% Increase trial
% Increases the trial, i.e. copies the data from handle of f_j to f_{j-1}, 
% and from handle of f_{j+1} to f_j. Same holds for e and y. 
if increase_trial
    % Output
    jj = 1;
    for ii = 1:3
        set(cell_handles{ii,jj}{2},'YData',cell_handles{ii,jj}{3}.YData) % Set p_{j-1} to p_j
        set(cell_handles{ii,jj}{3},'YData',NaN(size(cell_handles{ii,jj}{3}.YData))); % Set p_j to empty
    end
%     % Shaped reference
%     jj = 2;
%     for ii = 1:3
%         set(cell_handles{ii,jj}{2},'YData',cell_handles{ii,jj}{3}.YData) % Set r_y{j-1} to r_y_j
%         set(cell_handles{ii,jj}{3},'YData',NaN(size(cell_handles{ii,jj}{3}.YData))); % Set r_y_j to empty
%     end
    % shaped ref (test)
    jj = 2;
    for ii = 1:3
        set(cell_handles{ii,jj}{2},'YData',cell_handles{ii,jj}{3}.YData)  % Set r_y_{j-1} to r_y_j
        set(cell_handles{ii,jj}{3},'YData',cell_handles{ii,jj}{4}.YData); % Set r_y_j to r_y_{j+1}
%         set(cell_handles{ii,jj}{4},'YData',NaN(size(cell_handles{ii,jj}{4}.YData))) % Set r_y_{j+1} to empty
    end
    % Input
    jj = 3;
    for ii = 1:3
        set(cell_handles{ii,jj}{2},'YData',cell_handles{ii,jj}{3}.YData) % Set f_{j-1} to f_j
        set(cell_handles{ii,jj}{3},'YData',cell_handles{ii,jj}{4}.YData); % Set f_j to f_{j+1}
        set(cell_handles{ii,jj}{4},'YData',NaN(size(cell_handles{ii,jj}{4}.YData))) % Set f_{j+1} to empty
    end
    % Error
    jj = 4;
    for ii = 1:3
        set(cell_handles{ii,jj}{2},'YData',cell_handles{ii,jj}{3}.YData) % Set e_{j-1} to e_j
        set(cell_handles{ii,jj}{3},'YData',NaN(size(cell_handles{ii,jj}{3}.YData))); % Set e_j to empty
    end
%     % Contouring error (x,y) plot
%     jj = 6; ii = 1;
%     set(cell_handles{ii,jj}{2},'XData',cell_handles{ii,jj}{3}.XData,...
%         'YData',cell_handles{ii,jj}{3}.YData)
%     set(cell_handles{ii,jj}{3},'XData',NaN(size(cell_handles{ii,jj}{3}.XData)),...
%         'YData',NaN(size(cell_handles{ii,jj}{3}.YData)));

end
%% Update input f_{j+1}
if update_f_plus_one
    % Set f_j_plus_1 with new FFW
    jj = 3;
    for ii = 1:3
        set(cell_handles{ii,jj}{4},'YData',history.f(trial+1,:,ii))
    end
end

%% Update input f_j
if update_f_j
    % Set f_j with new FFW
    jj = 3;
    for ii = 1:3
        set(cell_handles{ii,jj}{3},'YData',history.f(trial,:,ii))
    end
end

%% Updating reference
% If reference is trial-varying, update_r flag can be given to update the
% references in the figure to the reference in the history struct at
% current trial, indicated by trial
if update_r
    % Set reference in output plot
    jj = 1;
    for ii = 1:3
        set(cell_handles{ii,jj}{4},'YData',history.r(trial,:,ii)); 
    end
%     % Set reference in contouring
%     ii = 1; jj = 6;
%     set(cell_handles{ii,jj}{4},'XData',history.r(trial,:,1),'YData',history.r(trial,:,2));
end

%% Updating shaped reference
if update_r_y
    % Set reference in output plot
    jj = 2;
    for ii = 1:3
        set(cell_handles{ii,jj}{3},'YData',history.r_y(trial,:,ii))
        set(cell_handles{ii,jj}{4},'YData',history.f(trial+1,:,ii))
    end
end

%% Update output, error and contouring errors
if update_y_e
    % Set y_j
    jj = 1;
    for ii = 1:3
        set(cell_handles{ii,jj}{3},'YData',history.p(trial,:,ii));
    end
    % Set e_j
    jj = 4;
    for ii = 1:3
        set(cell_handles{ii,jj}{3},'YData',history.e(trial,:,ii));
    end
    % Set norms of error
    jj = 5;
    for ii = 1:3
        cell_handles{ii,jj}{2}.YData(trial) = history.eNorm(trial,ii);
    end
%     % Set output in contouring plot
%     jj = 6; ii = 1;
%     set(cell_handles{ii,jj}{3},'XData',history.p(trial,:,1),'YData',history.p(trial,:,2));
end


drawnow()
end