# check if link time optimization is available and set it to the value ${ENABLE} to the target passed as input

function(target_enable_lto TARGET ENABLE)
    if(NOT  ${ENABLE})
        return()
    endif()

    include(CheckIPOSupported)
    check_ipo_supported(RESULT result OUTPUT output) # detect the compiler used and check if implement ipo

    if(result)
        message(STATUS "IPO/LTO is supported")
        set_property(TARGET ${TARGET} PROPERTY INTERPROCEDURAL_OPTIMIZATION ${ENABLE})
    else()
        message(WARNING "IPO/LTO is not supported")
    endif()
endfunction(target_enable_lto  )
