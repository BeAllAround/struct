
#ifndef UTILITY_DECLS

#define UTILITY_DECLS

using json = nlohmann::json;

// TODO: Don't use std::vector due to performance concerns as it is creating double copies, being the initializer_list first
using args_container = std::vector<json>;
using function_pointer = json(*)(args_container&&);
using JsonFunction = std::function<json(args_container&&)>;

// NOTE: Standard Library for now
template<class T_K, class T_V>
using hash_table = std::unordered_map<T_K, T_V>;

class Utility {
  private:
    hash_table<std::string, function_pointer> table;

  public:
    Utility() = default;

    void set_key(const std::string&, function_pointer);

    function_pointer& get_key(const std::string&);

    void set_table(hash_table<std::string, function_pointer>&&);

    function_pointer& operator[](const std::string&);

    ~Utility() = default;

};

class Provider {

  public:

    // NOTE: More dynamic approach compared to function overloading
    Provider(const json&);

    static Provider test(const json&);
    static Provider test(void);

    hash_table<std::string, Utility> utility(void);
};

#endif
