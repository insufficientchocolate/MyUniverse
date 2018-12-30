find_program(CLANG_FORMAT clang-format)
if(CLANG_FORMAT)
    function(format TARGET)
        get_target_property(target_sources "${TARGET}" SOURCES)
        foreach(p IN LISTS target_sources)
            list(APPEND source_abs "${CMAKE_CURRENT_SOURCE_DIR}/${p}")
        endforeach()
        add_custom_target(
            "format-${TARGET}" ALL
            "${CLANG_FORMAT}" -i -style=google ${source_abs}
        )
    endfunction()
else()
    function(format TARGET)
    endfunction()
endif()
