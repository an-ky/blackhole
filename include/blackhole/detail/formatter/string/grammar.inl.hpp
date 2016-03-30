#include <string>

#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <boost/optional/optional.hpp>

namespace blackhole {
inline namespace v1 {
namespace detail {
namespace formatter {
namespace string {

/// Represents parser grammar result.
/// Given: `{...:{{name}={value}:p}{, :s}>50s}`.
///     Spec: `>50s`.
///     Extension:
///         Pattern: `{name}={value}`.
///         Separator: `, `.
struct grammar_result_t {
    struct extension_t {
        boost::optional<std::string> pattern;
        boost::optional<std::string> separator;
    };

    extension_t extension;
    std::string spec;

    auto pattern() const -> boost::optional<std::string> {
        return extension.pattern;
    }

    auto separator() const -> boost::optional<std::string> {
        return extension.separator;
    }
};

auto parse(std::string pattern) -> grammar_result_t;
auto parse_pattern(std::string pattern) -> std::vector<ph::leftover_t::token_t>;

}  // namespace string
}  // namespace formatter
}  // namespace detail
}  // namespace v1
}  // namespace blackhole

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"

BOOST_FUSION_ADAPT_STRUCT(blackhole::detail::formatter::string::grammar_result_t::extension_t,
    (boost::optional<std::string>, pattern)
    (boost::optional<std::string>, separator)
)

BOOST_FUSION_ADAPT_STRUCT(blackhole::detail::formatter::string::grammar_result_t,
    (blackhole::detail::formatter::string::grammar_result_t::extension_t, extension)
    (std::string, spec)
)

#pragma clang diagnostic pop
