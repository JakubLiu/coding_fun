! This programme shows some functionalities of file IO operations
! First a file is opened (a better description of this process is in the file readCSV.f90)
! Then the mean of every column of the file is calculated
! Then the mean of each column is written to a new file (a better description of this process is in the file writeCSV.f90)
! QBA LIU 2023 ---------------------------------------------------------------------------------------------------------------

module read_file
        integer :: num_rows=0, i
        real :: col1, col2, col3, suma_col1, suma_col2, suma_col3
        real, dimension(3) :: array_of_means
end module read_file


module write_file
        integer :: num_rows_to_write = 3, j
end module write_file



program file_IO

        use read_file
        use write_file

        ! open a file and do some operations on it
        open (17, file = 'sample.csv')
        read(17, '()')
        get_number_of_rows: do
        read(17, *, end = 10) col1, col2, col3
                num_rows = num_rows + 1
        end do get_number_of_rows

        10 continue
        rewind(17)
        print*, 'NumRec=', num_rows
        print*, 'col1           ', 'col2        ', 'col3        '
        read(17, '()')
        read_all_rows: do i = 1,num_rows
                read(17, *) col1, col2, col3
                print*, col1, col2, col3
                suma_col1 = suma_col1 + col1
                suma_col2 = suma_col2 + col2
                suma_col3 = suma_col3 + col3
        end do read_all_rows

        array_of_means(1) = suma_col1/num_rows
        array_of_means(2) = suma_col2/num_rows
        array_of_means(3) = suma_col3/num_rows
        close(17)

        ! write the results of these operations to a new file
        open(18, file = "sample_out.csv")
               do j=1,num_rows_to_write
                        write(18, *) array_of_means(j)
               end do
        close(18)

end program file_IO
