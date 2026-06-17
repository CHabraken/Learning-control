function [PenColor] = penholder_settings(N_trial, ColorManualAuto, PenONOFF, PenColor)
%% Creating array
ArrayLength = numel(PenColor);

% If pen holder is off
if PenONOFF == 0
    PenColor = zeros(1,N_trial);
    
% If Manual is selected
elseif ColorManualAuto == 0
    if ArrayLength < N_trial
        PenColor = [PenColor ones(1,N_trial-ArrayLength)];
    end
    if PenColor(1) == 0
        PenColor(1) = 5;
    end
    
% If Auto is selected
elseif ColorManualAuto == 1
    PenColor = repmat([1 2 3 4],1,ceil(N_trial/4));    
end

% Remove access elements
ArrayLength = numel(PenColor);
for i = ArrayLength:-1:N_trial+1
    PenColor(i)=[];
end

% Replace unnecessary elements
for i = N_trial:-1:2
    if PenColor(i) == PenColor(i-1)
        PenColor(i) = 0;
    end
end

% Final element to lift pen
PenColor(N_trial+1) = 5;

end