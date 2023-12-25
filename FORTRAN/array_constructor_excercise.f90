! define an array using an array constructor
! the array has to be equal to: [3,5,3,5,3,5,3,5,3,5,5,5,5,5,4,3]

program array_constructor_test
        implicit none
        integer :: i
        integer, dimension(16) :: array
        array = (/(3,5,i=1,5), 5,5,5, (i, i=5,3,-1)/)
        ! repeat the '3,5' sequence 5 times
        ! then add '5,5,5'
        ! then add 5,4,3
        print*, array
end program array_constructor_test
