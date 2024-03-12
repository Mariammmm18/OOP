#include <vector>
#include<functional> 
namespace test
{
std::vector<int> map(std::vector<int> numbers, std::function<int(int)>);
std::vector<int> filter(std::vector<int> numbers, std::function<bool(int)>);
}
