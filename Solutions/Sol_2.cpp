#include <cstddef>
#include <cstdint>


namespace project_euler
{

[[nodiscard]] [[gnu::pure]]
std::size_t sum_even_fibonacci_numbers(std::size_t threshold) noexcept
{
	std::size_t fib_window[3] = {0, 1, 1};
	std::size_t sum = 0;
	std::uint8_t idx = 1;
	// [idx + 1] + [idx] = idx + 2

	std::size_t fib = 0;

	while(fib < threshold)
	{
		fib = fib_window[(idx + 2) % 3] = fib_window[idx] + fib_window[(idx + 1) % 3];
		idx = (idx + 1) % 3;

		sum += fib % 2 == 0 ? fib : 0;
	}

	return sum;
}

} // end of namespace project euler