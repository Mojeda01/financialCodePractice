# Book: Freddy Delbaen, Walter Schachermayer - The mathematics of Arbitrage
## 1.3 Pricing by No-Arbitrage

A different approach to the pricing of the option goes like this: we can buy at time $t=0$ a portolio
$\prod$ consisting of $\frac{2}{3}$ of stock and $-\frac{1}{3}$ of bond. The reader might be puzzled
about the negative sign: investing a negative amount into a bond - "going short" in the financial
lingo - means borrowing money.

Note that - although normal people like most of us may not be able to do so - the "big players" can go 
"long" as well as "short". In fact they can do so not only with respect to the bond (i.e. to invest or 
borrow money at a fixed rate of interest) but can also go "long" as well as "short" in other assets like 
shares. In addition, they can do so at (relatively) low transaction costs, which is reflected by completely
neglecting transaction costs in our present basic modelling.

Turning back to our portfolio $\prod$ one verifies that the value $\prod_1$, of the portfolio at time $t=1$
equals

$$
\prod_1(\omega)=
\begin{cases}
1 & \text{for } \omega = g \\
0 & \text{for } \omega = b.
\end{cases}
$$

The portfolio "replicates" the option, i.e.,

$$
C_1=\pi_1,
$$

or, written more explicitly,

$$
C_1(g)=\prod_1(g),\\
C_1(b)=\prod_1(b).
$$

We are confident that the reader now sees why we have chosen the above weights $2/3$ and $-1/3$: the 
mathematical complexity of determining these weights such that (1.2) and (1.3) hold true, amounts to 
solving two linear equations in two variables.

The portfolio $\prod$ has a well-defined price at time $t=0$, namely $\prod_0=2/3 S_0-1/3B_0=1/3$. Now comes 
the "pricing by no-arbitrage" argument: equality (1.1) implies that we also must have

$$
C_0=\prod_0
$$

whence $C_0=1/3$. Indeed, suppose that (1.4) does not hold true; to fix ideas, suppose we have 
$C_0=1/2$ as we had proposed above. This would allow an arbitrage by buying ("going long in") in the 
portfolio $\prod$ and simultaneously selling ("going short in") the option C. The difference 
$C_0 - \prod_0=1/6$ remains as arbitrage profit at time $t=0$, while at time $t=1$ the two 
positions cancel out independently of whether the random element $\omega$ equals $g$ or $b$.

Of course, the above considered size of the arbitrage profit by applying the above scheme to one 
option was only chosen for expository reasons: it is important to note that you may multiply the size 
of the above portfolios with your favourite power of ten, thus multiplying also your arbitrage profit.

At this stage we see that the story with the 100EUR bill at the beginning of this chapter did not fully 
describe the idea of an arbitrage: The correct analogue would be to find instead of a single 100EUR 
bill a "money pump", i.e., something like a box from which you can take one 100EUR bill after another.
Whule it might have happened to some of us, to accassionally find a 100EUR bill lying around, we are 
confident that nobody ever found such a "money pump".

Another aspect where the little story at the beginning of this chapter did not fully describe the idea
of arbitrage is the question of information. We shall assume throughout this book that all agents have 
the same information (there are no "insiders"). The theory changes completely when different stages 
have different information (which would correspond to the situation in the above joke). We will not 
address these extensions.

These arguments should convince the reader that the "no-arbitrage principle" is economically very 
appealing: in a liquid financial market there should be no arbitrage opportunities. Hence a mathematical 
model of a financial market should be designed in such a way that it does not permit arbitrage.

It is remarkable that this rather obvious principle yielded a unique price for the option considered 
in the above model.

## 1.5 Martingale Measures
To explain this notion let us turn back to our "toy example", where we have seen that the unique arbitrage
free price of our option equals $C_0=1/3$. We also have seen that, by taking expectations, we obtained
$\textbf{E}[C_1]=1/2$ as the price of the option, which was a "wrong price" as it allowed for arbitrage 
opportunities. The economic rationale for this discrepancy was that the expected return of the stock 
was higher than that of the bond.

Now make the following mind experiment: suppose that the world where governed by a different probability
than $\textbf{P}$ which assigns different weights to $g$ and $b$, such that under this new probability,
let's call it $\textbf{Q}$, the expected return of the stock equals that of the bond. An elementary 
calculation reveals that the probability measure defined by $\textbf{Q}[g]=1/3$ and 
$\textbf{Q}[b]=2/3$ is the unique solution satisfying $\textbf{E}_{\textbf{Q}}[S_1]=S_0=1$. Mathematically
speaking, the process $S$ is a martingale under $\textbf{Q}$, and $\textbf{Q}$ is a martingale measure for 
$S$.

Speaking again economically, it is not unreasonable to expect that in a world governed by $\textbf{Q}$,
the recipe of taking expected values should indeed give a price for the option which is compatible with the 
no-arbitrage principle. After all, our original objection, that the average performance of the stock and the 
bond differ, now has disappeared. A direct calculation reveals taht in our "toy example" these two prices
for the option indeed coincide as

$$
\textbf{E}_{\textbf{Q}}[C_1]=1/3.
$$

Clearly we suspect that this numerical match is not just a coincide. At this stage it is, of course, the 
reflex of every mathematician to ask: what is precisely going on behind this phenomenon? A preliminary
answer is that the expectation under the new measure $\textbf{Q}$ defines a linear function of the span 
of $B_1$ and $S_1$. The price of an element in this span should therefore be the corresponding linear 
combination of the prices at time $0$. Thus, using simple linear algebra, we get $C_0=2/3$S_0=-1/3B_0$ 
and moreover we identify this as $\textbf{E}_{\textbf{Q}}[C_1]$.

## 1.6 The Fundamental Theorem of Asset Pricing
To make a long story very short: for a general stochastic process $(S_t)_{0\le t \le T}$, modelled 
on a filtered probability space $(\Omega, (\mathcal{F}_t)_{0\le t \le T},\textbf{P})$, the following 
statement essentially holds true. For any "contingent claim" $C_T$, i.e., an $\mathcal{F}_T$-measure
random variable, the formula:

$$
C_0=\textbf{E}_{\textbf{Q}}[C_{\mathcal{T}}]
$$

yields precisely the arbitrage-free prices for $C_{\mathcal{T}}$, when $\textbf{Q}$ runs through the 
probability measures on $\mathcal{F}_T$, which are equivalent to $\textbf{P}$ and under which the 
process $S$ is a martingale ("equivalent martingale measures"). In particular, when there is 
precisely one equivalent martingale measure (as it is the case in the Cox-Ross-Rubinstein, the 
Black-Scholes and the Bachelier model), formula (1.5) gives the unique arbitrage free price $C_0$ for 
$C_T$. In this case we may "replicate" the contingent claim $C_T$ as

$$
C_T=C_0 + \int^T_0 H_t dS_t,
$$

where $(H_t)_{0\le t \le T}$ is a predictable process (a "trading strategy") and where $H_t$
models the holding in the stocks $S$ during the infinitesimal interval $[t,t+dt]$.

Of course, the stochastic integral appearing in (1.6) needs some care; fortunately people like $K$.
Ito and P.A. Meyer's sschool of probability in Strasbourg told us very precisely how to interpret such 
an integral.

The mathematical challenge of the above story consisting of getting rid of the word "essentially" and to 
turn this program into preceise theorems.

The central piece of theory relating the no-arbitrage arguments with martingale theory is the so-called 
Fundamental Theorem of Asset Pricing. We quote a general version of this theorem, which is proved in
Chap. 14.

### Theorem 1.6.1 (Fundamental Theorem of Asset Pricing) For an $R^d$ - valued semi-martingale $S=(S_t)_{0\le t \le T}$:

1.  There exists a probability measure $\textbf{Q}$ equivalent to $\textbf{P}$ under which $S$ is a 
    sigma-martingale.

2.  $S$ does not permit a free lunch with vanishing risk.

This theorem was proved for the case of a probability space $\Omega$ consisting of finitely many elements by 
Harrison and Pliska. In this case one may equivalently write no-arbitrage instead of no free lunch with 
vanishing risk and martingale instead of sigma-martingale.

In the general case it is unavoidable to speak about more technical concepts, such as sigma-martingales
(which is a generalisation of the notion of a local martingale) and free lunches. A free lunch (a notion 
introduced by D. Kreps is something like an arbitrage, where - roughly speaking - agents are allowed 
to form integrals as in (1.6), to subsequently "throw away money" (if they want to do so), and finally 
to pass to the limit in an appropriate topology. It was the - somewhat surprising - insight of [DS 94]
that one may take the topology of uniform convergence (whuch allows for an economic intepreration to which
the term "with vanishing risk" alludes) and still get a valid theorem.

The remainder of this book is devoted to the development of this theme, as well a to its remarkable 
scope of applications in Finance.
