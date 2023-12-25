program writeCSV
        implicit none
        integer, parameter :: n = 4 ! how many rows you want to write
        integer :: i
        
        ! here we define both columns (each has 4 rows) which we want to write (*they are initialized using an array constructor)
        real :: col1(n) = (/1.00, 2.00, 3.00, 4.00/)
        real :: col2(n) = (/10.00, 20.00, 30.00, 50.00/)
        
        ! open the file with the label '18' (can be any label)
        ! if a file with this name does not exist a new file will be created
        open(18, file = "example2.csv")
               ! iterate over the rows
               do i=1,n
                        write(18, *) col1(i), ',', col2(i) ! in each row write the value of col1 and col2 seperated by a comma
               end do
        close(18)
end program writeCSV
