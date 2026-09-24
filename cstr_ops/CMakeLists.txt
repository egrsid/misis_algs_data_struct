set(CMAKE_MAKE_PROGRAM 20)

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS "*.cpp")

foreach(source_file ${SOURCE_FILES})
    get_filename_component(exec_name ${source_file} NAME_WE)
    add_executable(${exec_name} ${source_file})
    
    # Получаем имя текущей папки (например, "cource_theory") и группируем в неё таргет
    get_filename_component(current_dir_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    set_target_properties(${exec_name} PROPERTIES FOLDER ${current_dir_name})
endforeach()