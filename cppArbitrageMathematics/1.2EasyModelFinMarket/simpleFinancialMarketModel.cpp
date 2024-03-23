#include <iostream>

//	Random - This library allows to produce random numbers using combinations of generators and distributions.
//	Generators:	Objects that generate uniformly distributed numbers.
//	Distributions:	Objects that transform sequences of numbers generated by a generator into sequences of numbers that
//					follow a specific random variable distribution, such as uniform, Normal or Binomial.

#include <random>

//	std::map is a sorted associative container that contains key-value pairs with unique keys. Keys are sorted by using the 
//	comparison function Compare. Search, removal, and insertion operations have logarithmic complexity. Maps are usually
//	implemented as Red-black trees (https://en.wikipedia.org/wiki/Red%E2%80%93black_tree).

#include <map>

//	Define the possible states of the world
enum class WorldState{Good, Bad};

//	Function to simulate the stock price
double simulateStockPrice(WorldState state){
	if(state == WorldState::Good){
		return 2.0;	//	Stock price doubles in the good state.
	} else{
		return 0.5;	//	Stock price halves in the bad state.
	}
}

//	Function to simulate the option price based on stock price and strike price
double simulateOptionPrice(double stockPrice, double strikePrice){
	double payoff = stockPrice - strikePrice;
	return (payoff > 0) ? payoff : 0; // Option payoff is max(S - K, 0)
}

int main(){
	const double bondPrice = 1.0;			//	Bond price is always 1
	const double strikePrice = 1.0;			//	Strike price for the option
	const double stockPriceToday = 1.0;		//	Today's stock price

	
	/*Simulate the world state*/

	//	std::random_device is a uniformly-distributed integer random number generator that produces non-deterministic random
	//	numbers. std::random_device may be implemented in terms of an implementation-defined pseudo-random number engine 
	//	if a non-deterministic source (e.g. a hardware device) is not available to the implementation. In this case each
	//	std::random_device object may generate the same number sequence.
	std::random_device rd;

	//	Mersenne Twister 19937 generator
	//	A Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits. It is an 
	//	instantiation of the mersenne_twister_engine with the following template parameters.
	std::mt19937 gen(rd());

	//	std::bernoulli_distribution produces random values, according to the discrete probability function.
	std::bernoulli_distribution d(0.5);	//	50% chance for good or bad state
	
	/*Run the simulation a large number of times*/

	std::map<WorldState, int> stateCounts;
	int numSimulations = 10000;
	double totalOptionValue = 0.0;

	for(int i = 0; i < numSimulations; ++i){
		WorldState state = d(gen) ? WorldState::Good : WorldState::Bad;
		stateCounts[state] += 1;

		//	Simulate stock and option prices
		double futureStockPrice = simulateStockPrice(state);
		double optionPrice = simulateOptionPrice(futureStockPrice, strikePrice);

		totalOptionValue += optionPrice;
	}

	//	Compute the expected option price
	double expectedOptionPrice = totalOptionValue / numSimulations;

	//	Outut the results
	std::cout << "After " << numSimulations << " simulations:" << std::endl;
	std::cout << "Good state count: " << stateCounts[WorldState::Good] << std::endl;
	std::cout << "Bad state count: " << stateCounts[WorldState::Bad] << std::endl;
	std::cout << "Expected option price: " << expectedOptionPrice << std::endl;

	//	Compare with the bond price
	std::cout << "Bond price: " << bondPrice << std::endl;

	return 0;
}