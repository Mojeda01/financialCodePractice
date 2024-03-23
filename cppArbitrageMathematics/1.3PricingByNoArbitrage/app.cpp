/*Implementing the Fundamental Theorem of Asset pricing would require a sophisticated understanding
 * of financial mathematics and stochastic calculus. The Fundamental Theorem of Asset Pricing 
 * states that if there exists a risk-neutral measure Q, under which the discounted stock price S
 * is a martingale, then the market is arbitrage-free. This means we can find a price 
 * for derivatives that does not allow for arbitrage opportunities (free profits without risk).
 *
 * The theorem involves complex mathematical concepts like sigma-algebras, martingales, measure theory,
 * and stochastic integration. This is a sketched simplified conceptucal C++ program that represent
 * the spirit of this theorem.
 *
 * 23.03.24
 *
 */

#include <iostream>

//	(1) std::vector is a sequence container that encapsulates dynamic size arrays, (2) std::pmr::vector
//	is an alias template that uses polymorphic allocator.
//	The elements are stored contiguously, which means that elements can be accessed not only through iterators,
//	but also using offsets to regular pointers to elements.
#include <vector>
#include <random>

//	Assume Black-Scholes model for simplicity
//	S(t) = S(0) * exp((mu - 0.5 * sigma^2) * t + sigma * W(t))
//	where W(t) is a Wiener process (Brownian motion)

double riskFreeRate = 0.01; // risk-free rate.
double volatility = 0.2;	//	volatility of the underlying asset.
double initialStockPrice = 100.0;	//	initial stock price.
double strikePrice = 100.0;	//	strike price of the option.
double maturity = 1.0;	//	time to maturity in years.

//	Function to simulate stock price using geometric Brownian motion
double simulateStockPrice(double initialPrice, double mu, double sigma, double time,
		std::default_random_engine& generator){

	std::normal_distribution<double> distribution(0.0, 1.0);
	double brownianMotion = distribution(generator) * sqrt(time);
	return initialPrice * exp((mu - 0.5 * sigma * sigma) * time + sigma * brownianMotion);

}

//	Pricing a European Call Option using risk-neutral valuation
double priceEuropeanCallOption(double initialPrice, double strike, double riskFree, double sigma,
		double maturity, int numSimulations){
		std::default_random_engine generator;
		double sumPayoffs = 0.0;

		for(int i = 0; i < numSimulations; ++i){
			double stockPriceAtMaturity = simulateStockPrice(initialPrice, riskFree, sigma, maturity,
					generator);
			double payoff = std::max(stockPriceAtMaturity - strike, 0.0);
			sumPayoffs += payoff;
		}

		double discountFactor = exp(-riskFree * maturity);
		return discountFactor * (sumPayoffs / numSimulations);
}

int main(){
	int numSimulations = 10000;
	double callOptionPrice = priceEuropeanCallOption(initialStockPrice, strikePrice, riskFreeRate,
			volatility, maturity, numSimulations);

	std::cout << "The price of the European Call Option is: " << callOptionPrice << std::endl;

	return 0;
}
