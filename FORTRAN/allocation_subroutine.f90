program allocation_subroutine
        implicit none
        real, allocatable :: array(:)
        integer :: arr_size
        arr_size = 10
        call alloc(array, arr_size)
        print*, allocated(array)
        call dealloc(array)
        print*, allocated(array)



        contains
                subroutine alloc(arr,n)
                        real, allocatable, intent(inout) :: arr(:)
                        integer, intent(in) :: n
                        
                        if(.not. allocated(arr)) then
                                allocate(arr(n))
                        else
                                print*, "Already allocated"
                        end if

                end subroutine alloc

                subroutine dealloc(arr)
                        real, allocatable,intent(inout) :: arr(:)

                        if (.not.allocated(arr)) then
                                print*, "Not allocated"
                        else
                                deallocate(arr)
                        end if

                end subroutine dealloc

end program allocation_subroutine
