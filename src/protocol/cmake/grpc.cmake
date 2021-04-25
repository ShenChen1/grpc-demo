function(grpc_generate_sources generated_sources input_file)
    get_filename_component(INPUT_FILENAME_BASE "${input_file}" NAME_WE)
    set(GENERATED_GRPC_SRCS "${INPUT_FILENAME_BASE}.grpc.pb.cc")
    set(GENERATED_GRPC_HDRS "${INPUT_FILENAME_BASE}.grpc.pb.h")
    set(GENERATED_PROTO_SRCS "${INPUT_FILENAME_BASE}.pb.cc")
    set(GENERATED_PROTO_HDRS "${INPUT_FILENAME_BASE}.pb.h")

    add_custom_command(
        OUTPUT "${GENERATED_GRPC_SRCS}" "${GENERATED_GRPC_HDRS}" "${GENERATED_PROTO_SRCS}" "${GENERATED_PROTO_HDRS}"
        COMMAND "${PROTOBUF_PROTOC}"
        ARGS
            --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
            --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
            --plugin=protoc-gen-grpc="${GRPC_CPP_PLUGIN}"
            -I "${CMAKE_CURRENT_SOURCE_DIR}/proto"
            "${input_file}"
        DEPENDS "${input_file}")

    set("${generated_sources}" "${GENERATED_GRPC_SRCS}" "${GENERATED_PROTO_SRCS}" PARENT_SCOPE)
endfunction(grpc_generate_sources)