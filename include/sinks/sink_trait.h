#ifndef LOGOLOCO_SINK_TRAIT_H
#define LOGOLOCO_SINK_TRAIT_H

#include <type_traits>
#include <string>

namespace LogoLoco {

template<typename Sink>
concept WritableSink = requires(Sink sink, const std::string &message) {
// Check if Sink can be written to
    { sink.write(message) } -> std::same_as<void>;
};

template<typename Sink>
concept PipeProperties = requires(Sink sink) {
    {sink.open() } -> std::same_as<void>;
    {sink.close() } -> std::same_as<void>;
};

template <typename Sink>
concept FileSinkConcept = WritableSink<Sink> && PipeProperties<Sink>;

template <typename... Args>
concept VariadicSinks = (WritableSink<Args> && ...);

}

#endif
