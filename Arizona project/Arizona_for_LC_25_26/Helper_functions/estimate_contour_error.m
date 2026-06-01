function [epsilon, epsilon_vec, refc] = estimate_contour_error(refx, refy, posx, posy, N_window, traj_is_rep)
%estimate_contour_error Estimates contour error of pos w.r.t. ref
%   Calculates the contour error epsilon as array with correspoding
%   dimension to posx. Each entry in epsilon indicates the contour error
%   corresponding to a position of [posx, posy].
%
% Author: Johan Kon
% Date:   April 2021
%
%   Inputs
%   * refx = [refx(1) refx(2) ... refx(Nref)] (double): row of reference
%   x positions with length Nref.
%   * refy = [refx(1) refx(2) ... refx(Nref)] (double): row of reference
%   y positions with length Nref.
%   * posx = [posx(1) posx(2) ... posx(Npos)] (double): row of measured x
%   positions with length Npos =/= Nref.
%   * posy = [posy(1) posy(2) ... posy(Npos)] (double): row of measured y
%   positions with length Npos (same as posx).
%   * traj_is_rep (bool): indicates if trajectory is repeating, i.e. if 
%   [refx(Nref+1) refy(Nref+1)]' = [refx(1) refy(1)]'. If true, final and 
%   first reference position are used in calculating contour error at last 
%   and first sample respectively. If false, reference is linearly 
%   extrapolated to obtain contour error at first and last sample.

%   Outputs
%   * epsilon_vec = [epsilon_x(1) epsilon_x(2) ... epsilon_x(Npos);
%                    epsilon_y(1) epsilon_y(2) ... epsilon_y(Npos)]: contour 
%   error vector corresponding to each position [posx(i) posy(i)]'. Note,
%   this is the normal vector, not the magnitude
%% Assertions and checks
assert(length(refx) == length(refy),"Reference arrays refx and refy don't have same length.")
assert(length(posx) == length(posy),"Position arrays posx and poxy don't have same length.")
% Check if row
if ~(size(refx,2) >= size(refx,1)); refx = refx'; end
if ~(size(refy,2) >= size(refy,1)); refy = refy'; end
if ~(size(posx,2) >= size(posx,1)); posx = posx'; end
if ~(size(posy,2) >= size(posy,1)); posy = posy'; end
%% Initialize
Npos = length(posx); 
Nref = length(refx);
pos = [posx; posy];
ref = [refx; refy];
distance = NaN*zeros(Nref,Npos); % Distance to each reference (row) from each position (column). Sparse matrix
epsilon_vec = zeros(2,Npos); % Error vector to linearly interpolated closest point of path. 
refc = zeros(2,Npos); % Closest point in reference to each positio
%% Calculate contour error
for ii = 1:Npos
    % Initial point for searching
    if ii == 1; ii_ref = ii; end % Search starts at start of reference
    if ii > 1; ii_ref = ii_ref + 1; end % Search starts at last reference point + 1
    % Make index range
    range = ii_ref-N_window:ii_ref+N_window;
    if traj_is_rep % Wrap range if repetitive
        range = mod(range-1,Nref)+1; 
    else % Set maximum and minimum index otherwise
        range = unique(min(max(range,1),Nref));
    end
    % Calculate distance to range of reference for this position
    distance(range,ii) = vecnorm(ref(:,range)-pos(:,ii));
    % Linearly interpolate between two points with minimum distance
    [~,jj] = min(distance(range,ii));
    kk = range(jj);
    if traj_is_rep; kk_plus = mod(kk,Nref)+1; kk_min = mod(kk-2,Nref)+1;
    else; kk_plus = min(kk+1,Nref); kk_min = max(kk-1,1); end
    kk_range = [kk_min, kk, kk_plus];
    h = calculate_h(ref(:,kk_range(1:end-1)),ref(:,kk_range(2:end)), pos(:,ii));
    % Check if any linear interpolation provides smaller distance
    if 0 <= h(1) && h(1) <= 1 % Perpendicular to line segment between ref(:,kk_min), ref(:,kk_plus)
        refc(:,ii) = (1-h(1))*ref(:,kk_min) + h(1)*ref(:,kk);
        assert( abs(dot(refc(:,ii) - pos(:,ii), ref(:,kk_min) - ref(:,kk)))<=10^-10,'Found distance not orthogonal')
    elseif 0 <= h(2) && h(2) <= 1 % Perpendicular to line segment between ref(:,,kk), ref(:,kk_plus)
        refc(:,ii) = (1-h(2))*ref(:,kk) + h(2)*ref(:,kk_plus); 
        assert( abs(dot(refc(:,ii) - pos(:,ii), ref(:,kk) - ref(:,kk_plus)))<=10^-10,'Found distance not orthogonal')
    else % Not perpendicular to any linear interpolation, just take closest point
        refc(:,ii) = ref(:,kk);
    end
    % Calculate contour error
    epsilon_vec(:,ii) = refc(:,ii) - pos(:,ii);
    % Set center of local window
    ii_ref = kk;
end
% Convert to time along first dimension
epsilon = vecnorm(epsilon_vec)';
epsilon_vec = epsilon_vec';
refc = refc'; 
end