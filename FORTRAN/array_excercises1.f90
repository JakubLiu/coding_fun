program array_excercises1
        implicit none
        real, dimension(50, 20) :: a
        integer :: i,j
        a = 1.00

        ! write the first row of a
        print *, a(1, 1:20)

        ! write the last column of a
        print *, a(1:50, 20)

        ! write every second element in each row and column of a
        do i=1,50,2
                do j=1,20,2
                        print*, a(i,j)
                end do
        end do

        ! write every second element in each row and column of a in reverse order
        do i=50,1,-2
                do j=20,1,-2
                        print *, a(i,j)
                end do
        end do
end program array_excercises1
