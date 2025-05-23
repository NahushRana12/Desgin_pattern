// Demonstration of the Open/Closed Principle using the Specification pattern

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Enum for product colors
enum class Color
{
    Red,
    Green,
    Blue
};

// Enum for product sizes
enum class Size
{
    Small,
    Medium,
    Large
};

// Product structure with name, color, and size
struct Product
{
    string name;
    Color color;
    Size size;

    Product(string name, Color color, Size size)
        : name(name), color(color), size(size) {}
};

// Forward declaration for AndSpecification
template<typename T>
struct AndSpecification;

// Specification interface for filtering
template<typename T>
struct Specification
{
    virtual ~Specification() = default;
    virtual bool isSatisfied(T* item) const = 0;

    // Overload && operator to combine specifications
    AndSpecification<T> operator&&(const Specification<T>& other) const
    {
        return AndSpecification<T>(*this, other);
    }
};

// Combines two specifications with logical AND
template<typename T>
struct AndSpecification : Specification<T>
{
    const Specification<T>& first;
    const Specification<T>& second;

    AndSpecification(const Specification<T>& first, const Specification<T>& second)
        : first(first), second(second) {}

    bool isSatisfied(T* item) const override
    {
        return first.isSatisfied(item) && second.isSatisfied(item);
    }
};

// Specification for filtering by color
struct ColorSpecification : Specification<Product>
{
    Color color;

    ColorSpecification(Color color) : color(color) {}

    bool isSatisfied(Product* item) const override
    {
        return item->color == color;
    }
};

// Specification for filtering by size
struct SizeSpecification : Specification<Product>
{
    Size size;

    explicit SizeSpecification(const Size size)
        : size(size) {}

    bool isSatisfied(Product* item) const override
    {
        return item->size == size;
    }
};

// Abstract filter interface
template <typename T>
struct Filter
{
    virtual ~Filter() = default;
    virtual vector<T*> filter(const vector<T*> items, const Specification<T>& spec) const = 0;
};

// Concrete filter implementation using specifications
struct BetterFilter : Filter<Product>
{
    vector<Product*> filter(const vector<Product*> items, const Specification<Product>& spec) const override
    {
        vector<Product*> result;
        for (const auto& item : items)
        {
            if (spec.isSatisfied(item))
            {
                result.push_back(item);
            }
        }
        return result;
    }
};

int main()
{
    // Create some products
    Product apple{"Apple", Color::Green, Size::Small};
    Product tree{"Tree", Color::Green, Size::Large};
    Product house{"House", Color::Blue, Size::Large};
    Product bigTree{"Big Tree", Color::Green, Size::Large};

    // Store all products in a vector
    const vector<Product*> all{ &apple, &tree, &house, &bigTree };

    BetterFilter bf;

    // Filter by color (Green)
    ColorSpecification Green(Color::Green);
    auto Green_things = bf.filter(all, Green);
    for (auto& x : Green_things)
        cout << x->name << " is Green\n";

    // Filter by size (Large)
    SizeSpecification Large(Size::Large);
    auto Large_things = bf.filter(all, Large);
    for (auto& x : Large_things)
        cout << x->name << " is Large\n";

    // Combine specifications: Green AND Large
    auto spec = Green && Large;
    for (auto& x : bf.filter(all, spec))
        cout << x->name << " is Green and Large\n";

    getchar(); // Wait for user input before exiting (Windows only)
    return 0;
}