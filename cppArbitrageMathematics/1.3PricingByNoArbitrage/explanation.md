# Code Explanation

## Assumptions
    double  riskFreeRate = 0.01
    double  volatility = 0.2
    double  initialStockPrice = 100.0
    double  strikePrice = 100.0
    double  maturity = 1.0

-   These are the parameters for the Black-Scholes model, which is a mathematical model for the dynamics
    of a financial market containing derivative investment instruments.

## Function to Simulate Stock Price - simulateStockPrice()
The function simulates the price of the stock at a future time using the geometric Brownian motion
formula from the Black-Scholes model. The 'brownianMotion' represents a single realization of the 
Wiener process (Brownian motion) over the time interval 'time'.

## Pricing a European Call Option - priceEuropeanCallOption()
This function calculates the price of a European call option by simulating 'numSimulations' possible
future stock prices at maturity, computing the payoff of the option for each simulation, and then taking 
the average. The average payoff is then discounted to present value using the risk-free rate.
The payoff of a call option is the maximum of 'stockPriceMaturity - strikePrice' or '0'.

## Main Function
    int numSimulations = 10000; //  Number of simulations to perform
    double callOptionPrice = priceEuropeanCallOption()
    std::cout << "The price of the European Call Option is: " << callOptionPrice << std::endl;

In the main function, "priceEuropeanCallOption" function is called with the defined parameters to 
compute the price of a European call option. The result is printed to the console.
