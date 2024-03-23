# From the book: Freddy Delbaen, Walter Schachemayer - The mathematics of Arbitrage
## 1 - The Story in a Nutshell
### 1.1 Arbitrage
The notion of arbitrage is crucial to the modern theory of Finance. It is the corner-stone of the option pricing theory 
due to F. Black, Merton and M. Scholes [BS73], [M73] (published in 1973, honoured by the Nobel prize in Economics 1997).

The idea of arbitrage is best explained by telling a joke: a professor working in mathematical Finance and a normal 
person go on a walk and the normal person sees a 100EUR bill lying on the street. When the normal person 
wants to pick it up, the profesor says: don't try to do that. it is absolutely impossible that there is a 100EUR bill lying 
on the street. Indeed, if it were lying on the street, somebody else would have picked it up before you. (end of joke).

How about financial markets? There it is already much more reasonable to assume that there are no arbitrage possibilities,
i.e., that there are no 100EUR bills lying around and waiting to be picked up. Let us illustrate this with an easy 
example.

Consider the trading of USD versus EUR that takes place simultaneously at two exchanges, say in New York and Frankfurt.
Assume for simplicity that in New York the USD/EUR rate is 1:1. Then it is quite obvious that in Frankfurt the
exchange rate (at the same moment of time) also is 1:1. Let us have a closer look why this is the case. Suppose to the 
contrary that you can buy in Frankfurt a USD for 0.999 EUR. Then, indeed, the so-called "arbitrageurs" (these are people 
with two telephones in their hands and three screens in front of them) would quickly act to buy USD in Frankfurt and 
simultaneously sell the same amount of USD in New York, keping th margin in their (or their's bank's) pocket. Note that
thre is no normalizing factor in front of the exchanged amount and the arbitrageur would try to do this on a scale as large 
as possible.

This brings us to a first - informal and intuitive - definition of arbitrage: an arbitrage opportunity is the possibility
to make a profit in a financial market without risk and without net investment of capital. The principle of no-arbitrage 
states that a mathematical model of a financial market should not allow for arbitrage possibilities.

### 1.2 An Easy Model of a Financial Market
To apply this principle to less trivial cases than the Euro/Dollar example above, we consider a still extremely simple
mathematical model of a financial market: there are two assets, called the bond and the stock. The bond is riskless,
hence by definition we know what it is worth tomorrow. For (mainly notional) simplicity we neglect interest rates and 
assume that the price of a bond equals 1 EUR today as well as tomorrow, i.e.,

$$
B_0=B_1=1
$$

The more interesting feature of the model is the stock which is risky: we know its value today, say (w.l.o.g.)

$$
S_0=1
$$

but we don't know its value tomorrow. We model this uncertainty stochastically by defining $S_1$ to be a random variable 
depending on the random element $\omega\in\Omega$. To keep things simple as possible, we let $\Omega$ consist of two 
elements only, $g$ for "good" and $b$ for "bad", with probability $\textbf{P}[g]=\textbf{P}[b]=\frac{1}{2}$. We define 
$S_1(\omega)$ by

$$
S_1(\omega) = 
\begin{cases}
2 & \text{for } \omega = g \\
\frac{1}{2} & \text{for } \omega = b
\end{cases}
$$

Now we introduce a third financial instrument in our model, an option on the stock with strike price $K$: the buyer
the option has the right - but not the obligation - to buy one stock at time $t=1$ at a predefined price $K$. To fix 
ideas let $K=1$. A moment's reflexion reveals that the price $C_1$ of the option at time $t=1$ (where $C$ stands for 
"call") equals

$$
C_1=(S_1 - K)_{+},
$$

i.e., in our simple example

$$
C_1(\omega) = 
\begin{cases}
1 & \text{for } \omega = g \\
0 & \text{for } \omega = b.
\end{cases}
$$

Hence we know the value of the option at time $t=1$, contingent on the value of the stock. But what is the price of the 
option today?

The classical approach, used by actuaries for centuries, is to price contingent claims by taking expectations. In our 
example this gives the value $C_0 := \textbf{E}[C_1]=1/2$. Although this simple approach is very successful in many 
actuarial applications, it is not at all satisfactory in the present context. Indeed, the rationale behind taking the 
expected value is the following argument based on the law of large numbers: in the long run the buyer of an option will
neither gain nor lose in the average. We rephrase this fact in a more financial lingo: the performance of an investment 
into the option would in averae equal the performance of the bond (for which we have assumed an interest rate equal to 
zero). However, a basic feature of finance is that an investment into a risky asset should in average yield a better 
performance than an investment into the bond (for the sceptical reader: at least, these two values should not necessarily 
coincide). In our "toy example" we have chosen the numbers such that $\textbf{E}[S_1]=1.25>1=S_0$, so that in average
the stock performs better than the bond. This indicates that the option (which clearly a risky investment) should not 
necessarily have the same performance (in average) as the bond. It also shows that the old method of calculating prices via 
expectation is not directly applicable. It already fails for the stock and hence there is no reason why the price of the 
option should be given by its expectation $\textbf{E}[C_1]$.



















