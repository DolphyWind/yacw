include(CTest)
enable_testing()

function(run_test exec_name src_name)    
    add_executable(${exec_name} ${src_name})
    target_link_libraries(${exec_name} yacw)
    add_test(NAME ${exec_name} COMMAND ${exec_name})
endfunction(run_test)

run_test(stringtest yacw_stringtest.cpp)
