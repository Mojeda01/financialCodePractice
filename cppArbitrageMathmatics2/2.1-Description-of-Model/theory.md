# Book: Freddy Delbaen - Walter Scachermayer, The Mathematics of Arbitrage
## 2 - Models of Financial Markets on Finite Probability Spaces
### 2.1 Description of the model

In this section we shall develop the theory of pricing and hedging of derivative securities in
financial markets.

In order to reduce the technical difficulties of the theory of option pricing to a minimum, we
assume throughout this chapter that the probability space $\Omega$ underlying our model will be
finite, say, $\Omega = \{ \omega_1,\omega_2,...,\omega_N\}$ equipped with a probability
measure $\textbf{P}$ such that $\textbf{P}[\omega_n]=p_n>0$, for $n=1,...,N$. This assumption
implies that all functional-analytical delicacies pertaining to different topologies on 
$L^\infty(\Omega,\mathcal{F},\textbf{P})$, $L^{1}(\Omega,\mathcal{F},\textbf{P})$,
$L^{0}(\Omega, \mathcal{F}, \textbf{P})$ etc. evaporate as all these spaces are simply
$\mathbb{R}^N$ (we assume w.l.o.g. that the $\sigma$-algebra $\mathcal{F}$ is the power set of
$\Omega$). Hence all the functional analysis, which we shall need in later chapters for the case of
more general processes, reduces in the setting of the present chapter to simple linear algebra. For
example, the use of the Hahn-Banach theorem is replaced by the use of the separating hyperplane
theorem in finite dimensional spaces.

Nevertheless we shall write $L^\infty(\Omega, \mathcal{F}, \textbf{P})$, 
$L^1(\Omega, \mathcal{F}, \textbf{P})$ etc. (knowing very well that in the present setting these 
spaces are all isomorphic to $\mathbb{R}^N$) is a contingent claim or an element of the dual 
space, i.e. a price vector.

In addition to the probability space $(\Omega, \mathcal{F}, \textbf{P})$ we fix a natural number
$T \ge 1$ and a filtration $(\mathcal{F}_t)^T_{t=0}$ on $\Omega$, i.e., an increasing 
sequence of $\sigma-algebras$. To avoid trivialities, we shall always assume that 
$\mathcal{F}_T=\mathcal{F}$, on the other hand, we shall not assume that $\mathcal{F}_0$ is
trivial, i.e., $\mathcal{F}_0 = \{ø,\Omega\}$, although this will be the case in most 
appliations. But for technical reasons it will be more convenient to allow for general
$\sigma$-algebras for $\mathcal{F}_0$.

We now introduce a model of a financial market in not necessarily discounted terms. The 
rest of Sect 2.1 will be devoted to reducing this situation to a model in discounted terms
which, as we shall see, will make life much easier.

-   **Definition 2.1.1.**:  A model of a financial market is an $\mathbb{R}^{d+1}$-valued
                            stochastic process $\hat{S}=(\hat{S}_t)^T_{t=0}=
                            (\hat{S}^0_{t},\hat{S}^1_{t},...,\hat{S}^d_t)^T_{t=0}$, based on
                            and adapted to the filtered stochastic base 
                            $(\Omega,\mathcal{F},(\mathcal{F}_t)^T_{t=0},\textbf{P})$. We shall
                            assume that the zero coordinate $\hat{S}_0$ satisfies
                            $\hat{S}^0_t>0$ for all $t=0,...,T$ and $\hat{S}^0_0=1$.

The interpretation is the following. The prices of the assets $0,...,d$ are measured in a fixed 
money unit, say Euros. For $1 \le j \le d$ they are not necessarily non-negative (think, e.g.
of forward contracts). The asset 0 plays a special role. It is supposed to be strictly positive
and will be used as a numeraire. It allows us to compare money (e.g., Euros) at time 0 to money 
at time $t>0$. In many elementary models, $\hat{S}^0$ is simply a bank account which in case 
of constant interest $r$ is then defined as $\hat{S}^0=e^{rt}$. However, it might also be 
more complicated, e.g., $\hat{S}^0_t=(r_0h+r_1h+...+r_{t-1}h)$ where $h>0$ is the length of the 
time interval between $t-1$ and $t$ (here kept fixed) and where $r_{t-1}$ is the stochastic
interest rate valid between $t-1$ and $t$. Other models are also possible and to prepare the 
reader for more general situations, we only require $\hat{S}^0_t$ to be strictly positive.
Notie that we only require that $\hat{S}^0_t$ to be $\mathcal{F}_t$-measurable and that it is
not necessarily $\mathcal{F}_{t-1}$ measurable. In other words, we assume that the process
$\hat{S}^0=(\hat{S}^0_{t})^T_{t=0}$ is adapted, but not necessarily predictable.

An economic agent is able to buy and sell financial assets. The decision taken at time $t$
can only use information available at time $t$ which is modelled by the $\sigma$-algebra
$\mathcal{F}_t$.

-   **Definition 2.1.2.**:  A trading strategy $(\hat{H})^T_{t=0}=(\hat{H}_t^0,
                            \hat{H}^1_t,...,\hat{H}^d_t)^T_{t=1}$ is an $\mathbb{R}^{d+1}$-
                            valued process which is predictable, i.e. $\hat{H}_t$ is
                            $\mathcal{F}_{t-1}$ measurable.

The interpretation is that between time $t-1$ and time $t$, the agent holds a quantity
equal to $\hat{H}^j_t$ of asset $j$. The decision is taken at time $t-1$ and therefore,
$\hat{H}_t$ is required to be $\mathcal{F}_{t-1}$-measurable.

**Definition 2.1.3.** A strategy $(\hat{H}_t)^T_{t=1}$ is called self-financing if for every 
$t=1,...,T-1$ we have

$$
\Big( \hat{H}_t, \hat{S}_t \Big) = \Big( \hat{H}_{t+1}, \hat{S}_t \Big
$$

or, written more explicitly

$$
\sum^d_{j=0}\hat{H}^j_t\hat{S}^j_t = \sum^d_{j=0} \hat{H}^j_{t+1} \hat{S}^j_t.
$$

The initial investment required for a strategy is $\hat{V}_0=(\hat{H}_1,\hat{S}_0)=
\sum^d_{j=0} \hat{H}^j_1 \hat{S}^j_0$.

The interpretation goes as follows. By changing the portfolio from $\hat{H}_{t-1}$ to $\hat{H}_t$
there is no input/output flow of money. We remark that we assume that changing a portfolio does not 
trigger transaction costs. Also note that $\hat{H}^j_t$ may assume negative values, which corresponds
to short selling asset $j$ during the time interval $[t_{j-1}, t_j]$.

The $\mathcal{F}_t$-measureable random variable defined in (2.1) is interpreted as the $\hat{V}_t$ of the 
portfolio at time $t$ defined by the trading strategy $\hat{H}$:

$$
\hat{V}_t = (\hat{H}_t,\hat{S}_t)=(\hat{H}_{t+1},\hat{S}_t).
$$

The way in which the value $(\hat{H}_t_\hat{S}_t)$ evolves can be described much easier when we use
discounted prices using the asset $\hat{S}^0$ as numeraire. Discounting allows us to compare money at 
time $t$ to money at time 0. For instance we could say that $\hat{S}^0_t$ units of money at time $t$
are the "same" as 1 unit of money, e.g., Euros, at time $0$. So let us see what happens if we replace prices
$\hat{S}$ by discounted prices $\frac{\hat{S}}{\hat{S}^0}=(\frac{\hat{s}}{\hat{S}_0},
\frac{\hat{s}^1}{\hat{s}^0},...,\frac{\hat{S}^d}{\hat{S}^0})$. We will use the notation

$$
S^j_t := \frac{\hat{S}^j_t}{\hat{S}^0_t}, \text{for } j=1,...,d \text{ and } t=0,...,T.
$$


