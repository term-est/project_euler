#include <cstddef>
#include "Utility/PrimeSieve.hpp"

namespace project_euler
{
static constexpr std::size_t sieve_size = 3'000'000;

[[nodiscard]] [[gnu::pure]]
std::size_t sum_of_primes(std::size_t n) noexcept
{
	PrimeSieve<sieve_size> s;
	s.populate();

	const auto &sieve = s.get_sieve();

	std::size_t sum = 0;

	for (int i = 0; i <= n; ++i)
	{
		if (sieve[i] == PRIME)
			sum += i;
	}

	return sum;
}

} // end of namespace project_euler