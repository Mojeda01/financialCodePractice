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

