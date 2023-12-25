program type_statements
        implicit none
        integer, dimension(100) :: int_arr
        integer :: i
        real, dimension(10,10) :: mat
        ! initialize a character string to the digits ’0’ to ’9’
        character(len=10) :: string = ’0123456789’

        ! initialize all the elements of an integer array of size 100 to the value 0
        int_arr = 0
        
        ! set all the odd elements of the previous array to 0 and then all the even elements to 1
        do i=1,100
                if (MOD(i,2) == 0) then
                        int_arr(i) = 1
                end if
        end do
        
        ! initialize all the elements of a real 10x10 matrix to 1.0
        mat = 1.0
end program type_statements
