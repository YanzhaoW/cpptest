#pragma once

#include <type_traits>
// ROOT types owned by ROOT: TH1, TF1;

class TF1;
class TH1;
class TTree;

namespace r3b
{
    template <typename... Types>
    struct TypeCollections
    {
    };

    using RootTypes = TypeCollections<TF1, TH1, TTree>;

    template <typename Type, typename>
    inline constexpr bool is_based_on = false;

    template <typename Type, typename... BaseTypes>
    inline constexpr bool is_based_on<Type, TypeCollections<BaseTypes...>> =
        (std::is_base_of_v<BaseTypes, Type> || ...);

    template <typename Type>
    inline constexpr bool can_rootOwn = is_based_on<Type, RootTypes>;

    template <typename RootType, typename... Args>
    inline auto root_owned(Args&&... args)
    {
        static_assert(can_rootOwn<RootType>, "UseRoot: such type cannot be owned by ROOT");
        return new RootType(std::forward<Args>(args)...); // NOLINT
    }
} // namespace r3b
