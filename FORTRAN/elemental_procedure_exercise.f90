! If a procedure has the 'elemental' attribute it can take both arrays and scalars as arguments.
! None, one or both arguments can be arrays.
! If both arguments are arrays then they have to be of the same size.


program elemental_procedure_exercise
        implicit none
        real :: array_1(4), array_2(4)
        real :: a = 17.00, b = 24.12
        array_1 = [10.00,8.00,2.00,12.00]
        array_2 = [11.00,432.00,-321.00,0.01]

        print*, "Function works on arrays:"
        print*, add(array_1,array_2)
        print*, "And on scalar values:"
        print*, add(a,b)
        print*, "It also works on a mixture of both:"
        print*, add(a,array_1)
        print*, "Thanks to the usage of 'elemental'."

contains
        pure elemental real function add(arr1, arr2) result(arr3)
                real, intent(in) :: arr1, arr2
                arr3 = arr1 + arr2
        end function add

end program elemental_procedure_exercise
