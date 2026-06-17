function [ai,bi,ci,di,phd] = zpetc(a,b,c,d,rho)
% ZPETC
%
% Given a discrete time SISO transfer function G(z^-1), which has zeros 
% on/outside the complex circle with radius rho, this function computes a 
% Zero-Phase Error Tracking Controller which cancels the zeros inside the 
% rho-circle, and provides zero phase compensation for zeros on/outside the 
% rho-circle, see [1] for more detail. N.B. For minimum phase systems an
% exact inverse is computed (without amplitude distortion).
%
% [ni,di,phd] = ZPETC(n,d,rho) uses zpetc with input arguments the numerator
% and denominator of the discrete time transfer function, together with a 
% value for rho (typically rho = 1). The output is returned as a numerator 
% and denominator, together with the number of delays introduced by the 
% zero-phase compensator (phd).
% 
% [zi,pi,ki,phd] = ZPETC(z,p,k,rho) uses zpetc with input arguments the 
% zeros (z), poles (p) and gain (k) of the discrete time transfer function,
% together with a value for rho. The output is returned in the same format,
% together with a value for phd.
%
% [ai,bi,ci,di,phd] = ZPETC(a,b,c,d,rho) uses zpetc with input arguments a
% state space realization (a,b,c,d) of the discrete time transfer function,
% together with a value for rho. The output is returned in the same format,
% together with a value for phd. The output format is flexible in a sense
% that it is independent of the input format, i.e. [zi,pi,ki,phd] = ZPETC(
% a,b,c,d,rho), [ni,di,phd] = ZPETC(z,p,k,rho) etc. are legal.
%
% REFERENCE:	[1] Tomizuka, M. "Zero Phase Error Tracking Algorithm for 
%                   Digital Control". Trans. ASME J. Dynamic Systems, 
%                   Measurement, and Control, Vol.109, 1987, pp. 65-68.
%
% AUTHOR:	D. de Roover
% DATE:		16-01-1995
% CHANGES:	13-03-1995
%		12-12-1995 (flexible input & output; robustification w.r.t
%                           num/den conversions by F.B. Sperling & AUTHOR)

% First some input checks:
% --------------------------------------------------------------------------- %

  nargs = nargin;
  error(nargchk(3,5,nargs));
  if (nargout > 5),
    error('Too many output arguments!')
  end,
  if (nargout < 3),
    error('Not enough output arguments!')
  end, 

  % check syntax:

  if (nargs == 3)
    [num,den] = tfchk(a,b);
    if (min(size(num)) > 1)
      error('Only SISO systems are considered!')
    end,
    [zz,pp,kk] = tf2zp(num,den);
    rho = c;
  elseif (nargs == 4)
    zz  = a;
    pp  = b;
    kk  = c;
    if (max(size(kk)) > 1)
      error('Only SISO systems are considered!')
    end,
    rho = d;
  elseif (nargs == 5)
    error(abcdchk(a,b,c,d))
    if (max(size(d)) > 1)
      error('Only SISO systems are considered!')
    end,
    [zz,pp,kk] = ss2zp(a,b,c,d,1);
  end,
  if ((max(size(rho)) > 1) | (imag(rho)~=0))
    error('rho has to be a real scalar value')
  end

% Next determine the number of delays:
% --------------------------------------------------------------------------- %

  tol = 1e12;
  z = [];
  del = abs(length(pp)-length(zz));
  for i = 1:length(zz),
    if (abs(zz(i)) > tol),
      kk  = -kk*zz(i);
      del = del+1;
    else
      z = [z;zz(i)];
    end,
  end,
  zz = z;

% Next split up the zeros in stable and unstable ones:
% --------------------------------------------------------------------------- %

  zz_min = [];
  zz_plus = [];
  l_zz = length(zz);
  for i = 1:l_zz,
    if abs(zz(i)) >= rho,
      zz_min = [zz_min;zz(i)];
    else
      zz_plus = [zz_plus;zz(i)];
    end,
  end,
  tol2 = 1e-10;
  w0 = 1;
  if abs(sum(real(poly(zz_min)))) < tol2,
    disp('    ');
    disp('  WARNING: sum of coefficients of unstable numerator nearly zero');
    disp('           at frequency 0; ouput may be garbage');
    w0 = rho;
  end,

% Finally construct the ZPETC:
% --------------------------------------------------------------------------- %

  zi  = [pp;1./zz_min];
  pi  = zz_plus;
  lzm = length(zz_min);
  zz_min_w0 = 1;
  zz_corr   = 1;
  for i = 1:lzm
    zz_min_w0 = zz_min_w0*(w0 - zz_min(i))*(1/w0 - zz_min(i));
    zz_corr   = zz_corr*(-zz_min(i));
  end,
  ki  = zz_corr/(kk*(zz_min_w0));
  phd = del+lzm;

  if (nargout == 3),
    [ai,bi] = zp2tf(zi,[pi;zeros(length(zi)-length(pi),1)],ki);
    ci = phd;
  elseif (nargout == 4),
    ai = zi;
    bi = pi;
    ci = ki;
    di = phd;
  elseif (nargout == 5),
    [ai,bi,ci,di] = zp2ss(zi,[pi;zeros(length(zi)-length(pi),1)],ki);
  end,
