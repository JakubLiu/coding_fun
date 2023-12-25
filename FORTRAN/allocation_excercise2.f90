! create a module
module container
        ! create a derived type
        type emfield
                real, allocatable :: strength(:,:)
        end type emfield
end module container


program main
        ! using the module
        use container
        ! declaring a variables of the derived type
        type(emfield) :: test_var, holder_var
        ! allocating memory space for the variable
        allocate(test_var%strength(1:4,1:6))
        ! setting all elements to 1.00
        test_var%strength = 1.00
        ! making a copy of the variable
        holder_var = test_var
        ! deallocating the variable
        deallocate(test_var%strength)
        ! allocating more memory locations to the variable
        allocate(test_var%strength(0:5, 0:8))
        ! setting all elements to 0.00
        test_var%strength = 0.00
        ! setting all elements in the given range to the old values
        test_var%strength(1:4, 1:6) = holder_var%strength
        print*, test_var%strength
end program main
