! actual arguemnts are arguments passed to the function/subroutine when it is called (print(f(a)) --> a is actual)
! dummy arguments are arguments defined in the function/subroutine definition (f(b){return(2b) --> b is dummy})
! intent(in) --> the dummy argument may be passed to the subroutine but may not be modified by it
! intent(out) --> the dummy argument may be modified by the subroutine

! this subroutine will return two variables: 'mean' and 'variance'
subroutine calculate(x,n, mean, variance)
        integer, intent(in) :: n                   ! the sample size
        integer, dimension(n), intent(in) :: x     ! the sample array
        real, intent(out) :: mean, variance        ! calculated mean and variance
        integer :: i,j, var_sum

        mean = 0.00
        variance = 0.00

        if (n > 0) then
                mean_loop: do i=1,n
                        mean = mean + x(i)
                end do mean_loop
                mean = mean/n

                variance_loop: do j=1,n
                        variance = variance + (x(j)-mean)*(x(j)-mean) 
                end do variance_loop
                variance = variance/n

        end if

end subroutine calculate

program subroutine_test
        implicit none
        integer, dimension(10) :: array_in
        integer :: arr_size, i
        real :: mean1, var1

        arr_size = 10

        fill_array: do i=1,arr_size
                array_in(i) = arr_size + i
        end do fill_array

        ! 'mean1' stands for 'mean' and 'var1' stands for 'variance'
        ! so I this call, 'mean1' and 'var1' will be returned
        call calculate(array_in, arr_size, mean1, var1)
        
        write(*,*) mean1, var1

end program subroutine_test
