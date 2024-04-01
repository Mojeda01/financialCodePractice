# Understanding nlohmann/json - source: https://github.com/nlohmann/json/tree/develop?tab=readme-ov-file#design-goals
## Design goals
There are myriads of JSON libraries out there, and each ay even have its reason to exist. Our class had these three design goals:
-   **Intuitive syntax**: In languages such as Python, JSON feels like a first class data type. we used all the operator magic of modern C++ to achieve the same feeling in your code.
-   **Trivial integration**: Our whole code consists of a single header file json.hpp. That's it. No library, no subproject, no dependencies, no complex build system. The class is written in vanilla C++11. All in all, everything should require no adjustment of your compiler flags or project settings.
-   **Serious testing**: our code is heavily unit-tested and covers 100% of the code, including all exceptional behavior. Furthermore, we checked with Valgrind and the Clang Sanitizers that there are no memory leaks. Googls OSS-Fuzz additionally runs fuzz tests against all parses 24/7, effectively executing billions of tests so far. To maintain high quality, the project is following the Core Infrastructure Initiative (CII) best practices.

Other aspects were not so important to us:

-   **Memory efficiency**: Each JSON object has an overhead of one pointer (the maximal size of a union) and one enumeration element (1 byte). The default generalization uses the following C++ data types: std::string for strings, int64_t, uint64_t, or double for numbers, std::map for objects, std::vector for arrays, and bool for Booleans. However, you can template the generalize class basic_json to your needs.

-   **Speed**. There are certainly faster JSON libraries out there. However, if your goal is to speed up your development by adding JSON support with a single header, then this library is the way to go. If you know how to use a std::vector or std::map, you are already set.


