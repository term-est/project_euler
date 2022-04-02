#include <string>
#include <cstddef>

namespace project_euler
{

[[nodiscard]] [[gnu::pure]]
std::size_t largest_product(std::string_view str, std::size_t window) noexcept
{

	std::size_t max_product = 0;

	for (int i = 0; i < str.size() - window; ++i)
	{
		std::size_t product = 1;

		for (int j = 0; j < window; ++j)
		product *= str[i + j] - '0';

		max_product = max_product > product ? max_product : product;
	}

	return max_product;
}

} // end of namespace project_euler