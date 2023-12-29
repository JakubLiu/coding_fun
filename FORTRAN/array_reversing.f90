program arr_reverse
        implicit none

        real :: arr1(5)
        real, allocatable :: arr2(:)
        real, allocatable :: arr3(:)
        arr1 = [1.00,2.00,3.00,4.00,5.00]
        arr2 = reverse(arr1)
        arr3 = smarter_reverse(arr1)
        print*, arr2
        print*, arr3
        print*, all(arr1 == reverse(reverse(arr1)))
        print*, all(arr1 == smarter_reverse(smarter_reverse(arr1)))
        

        contains
                pure function reverse(array_in) result(array_out)
                        real, intent(in) :: array_in(:)
                        real :: array_out(size(array_in))
                        integer :: i
                        integer :: j
                        j = 1
                        do i=size(array_in), 1, -1
                                array_out(j) = array_in(i)
                                j = j + 1
                        end do
                end function reverse


                pure function smarter_reverse(array_in) result(array_out)
                        real, intent(in) :: array_in(:)
                        real :: array_out(size(array_in))
                        array_out = array_in(size(array_in):1:-1)  ! from end to start with stride 1
                end function smarter_reverse

end program arr_reverse
