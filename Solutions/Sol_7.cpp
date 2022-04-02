#include <cstddef>
#include "Utility/PrimeSieve.hpp"

namespace project_euler
{

static constexpr std::size_t sieve_size = 3'000'000;

[[nodiscard]] [[gnu::pure]]
std::size_t nth_prime(std::size_t n) noexcept
{
	PrimeSieve<sieve_size> s;
	s.populate();

	const auto& sieve = s.get_sieve();

	std::size_t i = 1;

	for (i = 0; n != 0; ++i)
	{
		if(sieve[i] == PRIME)
			--n;
	}

	return --i;
}

} // end of namespace project_euler