program readCSV
        implicit none
        integer :: n,i
        real :: col1, col2, col3, col4   ! how many columns you want to read
        
        open (17, file = 'example.csv')   ! 17 is the file ID (can be any number)

        n = 0   ! n counts the number of records (rows)
        
        read(17, '()')

        ! I think this do loop is just to get the number of rows into memory
        get_number_of_rows: do
        ! read 4 columns in each row and increment n
        read(17, *, end = 10) col1, col2, col3, col4  ! 10 is just a tag for the do ---> contiunue statement
                n = n + 1
        end do get_number_of_rows
        
        10 continue ! continue is there to terminate the read() statement (it reffers to the tag '10')
        rewind(17)  ! return to the beggining of the file with the ID '17'

        ! this is just to print a neat header
        print*, 'NumRec=', n
        print*, 'col1           ', 'col2        ', 'col3        ', 'col4        '

        read(17, '()')
        
        ! This is do loop is to read all rows up to n (we got n from the previous do loop)
        ! so if we wanted to read not all but several rows we would not need the previous do loop
        ! inside this loop we go through each row and read 4 columns (col1, ..., col4)
        ! inside this loop we can do whatever we want on every record of the file
        read_all_rows: do i = 1,n
                read(17, *) col1, col2, col3, col4
                print*, col1, col2, col3, col4
        end do read_all_rows
        
        close(17)

end program readCSV
