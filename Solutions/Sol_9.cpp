#include <cstddef>

namespace project_euler
{


[[nodiscard]] [[gnu::pure]]
std::size_t pythagoras_triple(std::size_t upper_limit) noexcept
{
	auto pythagoras = [](std::size_t a, std::size_t b) -> std::size_t
	{
		return (a * a) + (b * b);
	};

	for (std::size_t i = 1; i <= upper_limit; ++i)
	for (std::size_t j = 1; j <= upper_limit - i; ++j)
	{
		std::size_t k = upper_limit - (i + j);


		if (pythagoras(i, j) == (k * k))
			return i * j * k;
	}

	return 0;
}

} // end of namespace project_euler