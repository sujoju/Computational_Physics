# Problem 1

The bifurcation diagram as well as the magnified version can be seen in 
"assignment5_1.png" and "assignment5_1_zoom.png", respectively.

From these diagrams, we can see that the period-2 regime extends from 
$F_{D} \approx 1.425$ to $F_{D} \approx 1.460$. Furthermore, we see that the period-4
regime extends from $F_{D} \approx 1.460$ to $F_{D} \approx 1.4764$. Finally, we see
that the period-8 regime extends from $F_{D} \approx 1.4764$ to $F_{D} \approx 1.4778$.
These values for $F_{D}$ were found by restricting the domain of our plots until we
reached a value where the previous period regimes ended; we then checked these values
with the data that we collected to make sure that this was indeed the case. 

With these values of $F_{D}$, we can calculate the Feigenbaum $\delta$ as follows:
$$
\delta_{n}
=
\frac{F_{n} - F_{n - 1}}{F_{n + 1} - F_{n}}
$$
where $F_{n}$ is defined to be the value of the driving force at which the transition to 
period-$2^{n}$ behavior takes place.
We see 
$$
\delta_{2}
=
\frac{F_{2} - F_{1}}{F_{3} - F_{2}}
=
\frac{1.460 - 1.425}{1.4764 - 1.460}
\approx
2.134
$$
and 
$$
\delta_{3}
=
\frac{F_{3} - F_{2}}{F_{4} - F_{3}}
=
\frac{1.4764 - 1.460}{1.4778 - 1.4764}
\approx
11.714
$$
From these calculated values, we find that we are quite far from the expected value
of $\delta \approx 4.699 \ldots$. However, this value only occurs if we take $n$ to 
go to $\infty$. If we took finer data, then we would be able to obtain more and more 
values of $F_{n}$; doing so would most likely result in us obtaining a more accurate
value for $\delta$.

# Problem 2

(a) The summary report for this fit taken from higgs_BGonly.log) is as follows:

summary from method 'trust-region/levenberg-marquardt' \
number of iterations: 8 \
function evaluations: 9 \
Jacobian evaluations: 9 \
reason for stopping: small step size \
initial |f(x)| = 187.909805 \
final   |f(x)| = 10.596390 \
chisq/dof = 1.96989 \
Ab     = 1693.24964 +/- 20.35516 \
tau    = -20.34237 +/- 0.22290 \
status = success

We note that we took $x_{0} = 100$ for this fit, and see the resulting fitted values
for $A_{b}$ and $\tau$ to be very similar to what was given in lecture 
(especially $\tau$). We note that $A_{b}$ is larger than what was given in lecture, and
this makes sense as the value for $x_{0}$ given in lecture was larger than $100$; we 
saw in lecture that the large uncertainties for $A_{b}$ and $x_{0}$ reflect the freedom 
to change in tandem.
Thus, to account for a lower $x_{0}$, we need to increase $A_{b}$, which explains the
higher value of $A_{b}$ that we found.

The plot for this fit can be seen in "mgg_BGonly.png".

(b) The summary report for this fit (taken from higgs_sig_bgfixed.log) is as follows:

summary from method 'trust-region/levenberg-marquardt' \
number of iterations: 23 \
function evaluations: 33 \
Jacobian evaluations: 24 \
reason for stopping: small step size \
initial |f(x)| = 71.691813 \
final   |f(x)| = 6.185002 \
chisq/dof = 0.671127 \
As      = 129.65213 +/- 18.60049 \
mu      = 126.21534 +/- 0.22568 \
sigma   = 1.41973 +/- 0.22242 \
status = success

From this report, we see that we obtained the very similar results as given in lecture. 

The plot for this fit can be seen in "mgg_sig_bgfixed.png".

(c) The summary report for this fit (taken from higgs_sig_bg2comp.log) is as follows:

summary from method 'trust-region/levenberg-marquardt' \
number of iterations: 23 \
function evaluations: 39 \
Jacobian evaluations: 23 \
reason for stopping: small step size \
initial |f(x)| = 75.207578 \
final   |f(x)| = 5.529639 \
chisq/dof = 0.555944 \
As      = 133.31455 +/- 17.42455 \
mu      = 126.17796 +/- 0.23410 \
sigma   = 1.63495 +/- 0.23832 \
Ab      = 1687.23244 +/- 14.63853 \
tau     = -20.08283 +/- 0.16297 \
status = success

From this report, we see that we again obtained the exact same results as given in 
lecture. When compared to the values we got in parts (a) and (b), we see that the values
we got for $A_{s}$ and $\sigma$ are slightly larger; the values we got for $A_{b}$,
$\mu$, and $\tau$ were slightly smaller. We should expect these changes -- especially 
for $A_{s}$ and $A_{b}$. This is because fixing the background will result in the 
value for $A_{b}$ to be higher than not fixing it; fixing it means that the signal
is being accounted for in the fit, and since these signal values were larger than the
expected exponential, this ultimately will shift our fitted exponential upwards 
slightly. Thus, we see that the value for the fixed $A_{b}$ is larger than the unfixed
$A_{b}$. Likewise, we have that $A_{s}$ will have to increase in the unfixed signal
as lowering the fitted exponential will require the peak of the signal to increase if
we were to keep the same overall height of the peak.

The plot for this fit can be seen in "mgg_sig_bg2comp.png".

