#include "blackhole/sink/null.hpp"

#include "blackhole/cpp17/string_view.hpp"
#include "blackhole/record.hpp"

namespace blackhole {
inline namespace v1 {
namespace sink {

auto null_t::emit(const record_t&, const string_view&) -> void {}

}  // namespace sink

auto factory<sink::null_t>::type() -> const char* {
    return "null";
}

auto factory<sink::null_t>::from(const config::node_t&) -> sink::null_t {
    return sink::null_t();
}

}  // namespace v1
}  // namespace blackhole
