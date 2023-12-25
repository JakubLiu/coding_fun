program array_excercise_2
        implicit none
        integer, dimension(10, 10) :: z
        z = 1
        ! double the value of all positive elements of z, in our case all the elements
        where (z > 0) z = 2*z
        print*, z
end program array_excercise_2
