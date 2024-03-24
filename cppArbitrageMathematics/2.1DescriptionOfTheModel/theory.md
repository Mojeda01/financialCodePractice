# From the book: Freddy Delbaen, Walter Schachermayer - The Mathematics of Arbitrage
# 2: Models of Financial Markets on Finite Probability Spaces
## 2.1 Description of the Model

In this section we shall develop the theory of pricing and hedging of derivative securities in financial
markets.

In order to reduce the technical difficulties of the theory of option pricing to a minimum, we assume 
throughout this chapter that the probability space $\Omega$ underlying our model will be finite, say,
$\Omega=\{\omega_1,\omega_2,...,\omega_N\}$ equipped with a probability measure $\textbf{P}$ such that 
$\textbf{P}[\omega_w]=p_n>0$, for $n=1,...,N$. This assumption implies that all functional-analytical
delicacies pertaining to different topologies on $L^\infty(\Omega,\mathcal{F},\textbf{P})$,
$L^1(\Omega,\mathcal{F},\textbf{P})$,$L^0(\Omega,\mathucal{F},\textbf{P})$ etc. evaporate, as all these 
spaces are simply $\mathbb{R}^N$ (we assume that the $\sigma$-algebra $\mathcal{F}$ in later chapters
for the case of more general processes, reduces in the setting of the present chapter to simple linear 
algebra. For example, the use of the Hahn-Banach theorem replaced by the use of the separating hyperplane
theorem in finite dimensional spaces.

***
### Giving a clearer understanding of the above!
1.  **Finite Probability Space:**   The authors simplify the complexity of financial models by assuming
                                    a finite probability space, $\Omega$, which consists of a limited 
                                    number of possible outcomes or states of the world, denoted as
                                    $\omega_1,\omega_2,...,\omega_N$. Each outcome has a probability
                                    associated with it.

2.  **Probability Measure** $P$:    A probability measure $P$ is defined on this space such that each 
                                    outcome $\omega_i$ has a probability $P(\omega_i)=p_i$, where 
                                    $p_i$ is a non-negative number and the sum of all $p_i$ equals
                                    (i.e., probabilities must add up to 1).

3.  **Technical Simplifications**:  By restricting the probability space to a finite number of outcomes,
                                    the authors avoid the complexities of continuous models that require
                                    advanced mathematical concepts such as functional analysis and different
                                    topologies. The functional-analytical delicacies they refer to may
                                    include tools and theorems from measure theory, topology, and functional
                                    spaces that are used in more advanced settings.

4.  **Linear Spaces and the Hahn-Banach Theorem**:  They suggest that for the finite case they are considering

