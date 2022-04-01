#include <cstddef>

namespace project_euler
{

[[nodiscard]] [[gnu::pure]]
std::size_t largest_prime_factor(std::size_t number) noexcept
{
	std::size_t max_prime_factor = 1;

	for(std::size_t i = 2; i <= number; ++i)
	{

		if(number % i != 0)
			continue;

		number = number / i;
		max_prime_factor = max_prime_factor > i ? max_prime_factor : i;
	}

	return max_prime_factor;
}

} // end of namespace project_euler