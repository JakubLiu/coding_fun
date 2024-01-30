! USAGE *****************************************************************************************************************
! cafrun needs to be installed (for example with "sudo apt install cafrun")
! compile: caf ParallelMax.f90 -o <name of executable>
! run: cafrun -n <integer number of images> ./<name of executable>

! PURPOSE ***************************************************************************************************************
! Demonstrate the builtin Fortran parallel features by calculating the maximum value in an array.
! Take a split, apply, combine approach.
! Split the array into chunks, calculate the max of each chunk, then find the total max

! more information: "Modern Fortran" by Milan Curcic. Pages 173-201.

program ParallelMax
        implicit none
        integer, parameter :: ARRAY_SIZE = 1000000
        integer, dimension(ARRAY_SIZE):: data ! declare array of size 1 million
        integer, dimension(2) :: bounds    ! array to hold the upper and lower bound of each chunk
        integer :: i
        integer :: total_max
        
        ! populate array
        do i=1,ARRAY_SIZE
                data(i) = i
        end do
        
        ! insert the highest element somewhere into the array just for verification of the method
        data(100) = 2000000
        
        ! for each image get the start and end of a chunk
        bounds = SubArrayBounds(size(data))
        
        ! each image will have its own total_max
        total_max = maxval(data(bounds(1) : bounds(2)))
        
        ! find the highest total_max across all images
        call co_max(total_max)
        
        ! print it for some image, doesnt have to be exactly image 1
        if(this_image() == 1) then
                print*, total_max
        end if
        

        contains
                ! function to create the bounds of the chunks
                ! each image will have its own upper and lower bound
                pure function SubArrayBounds(input_size)
                        integer, intent(in) :: input_size
                        integer :: input_size_new
                        integer :: SubArrayBounds(2)
                        integer :: chunk_size
                        integer :: remainder
                        integer :: diff
                        integer :: lower_bound
                        
                        remainder = mod(input_size, num_images())
                                                
                        if(remainder == 0) then   ! if the array size is divisable by the number of images                     

                                chunk_size = input_size/num_images()
                                
                                if(this_image() == 1) then    ! special case for first chunk
                                        SubArrayBounds(1) = 1
                                        SubArrayBounds(2) = chunk_size
                                else    ! all other chunks
                                        SubArrayBounds(1) = chunk_size*(this_image()-1)+1
                                        SubArrayBounds(2) = chunk_size*this_image()
                                end if
                        
                        else    ! if the number of chunks is not divisable by the number of images
                                input_size_new = input_size - remainder
                                
                                chunk_size = input_size_new/num_images()

                                if(this_image() == 1) then      ! special case for first chunk
                                        SubArrayBounds(1) = 1
                                        SubArrayBounds(2) = chunk_size

                                else if(this_image() == num_images()) then   ! special case for last chunk
                                        diff = input_size - input_size_new
                                        lower_bound =  input_size - diff + 1
                                        SubArrayBounds(1) = lower_bound
                                        SubArrayBounds(2) = input_size
                                else                                     ! all other chunks
                                        SubArrayBounds(1) = chunk_size*(this_image()-1)+1
                                        SubArrayBounds(2) = chunk_size*this_image()
                                end if
                        end if
                end function SubArrayBounds
end program ParallelMax
