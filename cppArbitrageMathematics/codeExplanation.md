# Code Explanation
This C++ code implements a simple financial market model for educational purposes. Here's a deep-dive into how it works.

## Incude Directives
    -   #include <iostream>:    for input/output streams
    -   #include <random>:  for random number generation
    -   #include <map>: for storing state counts in a map

These lines include the necessary libraries: 'iostream' for console input/output, 'random' for generating random numbers 
to simulate the randomness of market conditions, and 'map' to store and count occurrences of each market condition.

## Enum Class
    -   enum class WorldState{Good, Bad};
An enumeration is defined to represent two possible states of the world, "Good" and "Bad". The 'enum class' provides 
type safety over traditional enums.

## Simulations Functions
double simulateStockPrice(WorldState state){
    if(state == WorldState::Good){
        return 2.0;
    } else{
        return 0.5;
    }
}

The simulateOptionPrice function(double stockPrice, double strikePrice){
    double payoff = stockPrice - strikePrice;
    return (payoff > 0) ? payoff : 0;
}

The 'simulateOptionPrice' calculates the payoff of a call option based on the simulated stock price and the option's 
strike price. The payoff is the maximum of 'stockPrice - strikePrice' and 0, representing the non-negative payoff 
characteristic of call options.

## Main Function
The 'main' function sets constants for bond and strike prices and initiaizes the random number generation utilities.

    -   std::random_device rd;  :   non-deterministic random number generator
    -   std::mt19937 gen(rd()); :   Mersenne Twister pseudo-random generator
    -   std::bernoulli_distribution d(0.5); :   50% chance for good or bad state.

These lines set up a random number generator. The 'std::random_device' provides a seed for the 'std::mt19937'
(a Mersenne Twister engine), and a 'std::bernoulli_distribution' is used to simulate a 50/50 chance of "Good"
or "Bad" outcomes.

## Simulation Loop
The code runs a loop 10,000 times to simulate many outcomes:

for(int i = 0; i < numSimulations; ++i){
        WorldState state = d(gen) ? WorldState::Good : WorldState::Bad;
        stateCounts[state] += 1;
        //  Simulate stock and option prices
        //  ...
        totalOptionValue += optionPrice;
}

For each iteration, it simulates a world state, updates the count of that state, calculates the stock price and 
option price, and accumulates the option price.

## Computing the Expected Option Price

double expectedOptionPrice = totalOptionValue / numSimulations;

This line calculates the average option price across all simulations, representing the expected price of the option.

## Output
Finally, the program outputs the simulation results and compares the expected option price with the constant bond price.

## Mathematical Relationship
The code models a simple financial world where a stock has only two possible outcomes (good or bad). The bond price is 
fixed, and the option price depends on the stock's performance. Mathematically, the expected value of the option is 
computed by averaging its payoff over many simualted outcomes, which is a Monte Carlo simulation method. This is related 
to the concept of risk-neutral valuation in finance, where the expected return of a security is adjusted for risk, and 
hence, the price of an option should be its expected payoff under these risk-neutral probabilities, discounted back to the 
present value. However, this code does not include the discounting step since it assumes a single time step and a risk-free
rate of 0.

The code thus captures the essence of financial mathematics where probabilities and random processes (stochastic processes)
play a crucial role in determining the prices of securities.

# Result interpretation
The output of the program indicates the results after running 10,000 simulations of the simple financial model. 
Here's the interpretation of each line:

-   **Good state count: 5094** - In 5094 out of 10,000 simulations, the stock price doubled (representing a 
    "Good" state og the world).
-   **Bad state count: 4906** - In 4906 out of 10,000 simulations, the stock price halved (representing a "Bad"
    state of the world).

The counts for "Good" and "Bad" states are almost even, as expected, given the 50% probability for either state. This 
reflects the randomness of the market conditions being simulated.

-   **Expected Option price: 0.5094** - The average or expected price of the call option across all simulations is approximately
    0.5094. This is calculated based on the payoff of the option in each state. The option price reflects the itrinsic value
     of the option at expiration. Since the option is a derivative whose value is contingent on the stock price, its
     expected price in a risk-neutral world is a probabilistic expectation of its payoff.

-   **Bond Price: 1** - The price of bond is given as 1. This is consistent throughout because the bond is considered riskless
    in this model, and its value does not change regardless of the state of the world.

In terms of financial interpretation, the output shows that the expected price of the option is slightly higher than 0.5.
This is because in the "Good" state, the stock price would be 2, and since the strike price is 1, the option would be 
in the money, giving it a value of 1 (stock price - strike price). In the "Bad" state, the option would be out of the money
and thus worthless (0 value). Since the two states are equally likely, the expected value is slightly above 0.5 due to the 
slight asymmetry in the state counts. The expected option price is thus a weighted average of the option's payoff in each 
state.
