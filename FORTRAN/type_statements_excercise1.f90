program type_statements1
        implicit none
        
        ! an array to hold the count values for each of the 100 histogram bins
        integer, dimension(100) :: hist

        ! an array to hold the temperature to two decimal places at points (on a sheet of iron) that are spaced at 1cm intervals on a          20cm square
        real(selected_real_kind(p = 2, r = 99)), dimension(1:20, 1:20) :: temp
        ! p is the number of decimal places
        ! r specifies the size of the number that can be stored in the array
        ! in our example we can store a number from the range 10^-99 to 10^99 with the precision of 2 decimal places

        ! an array to describe 20 on/of switches
        logical, dimension(20) :: switch

        ! an array to contain the information destined for a printed page of 44 lines, each of 70 letters or digits
        character(len=70), dimension(70) :: page
end program type_statements1
