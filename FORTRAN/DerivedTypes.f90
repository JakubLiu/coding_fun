module mod_car
        type :: car
                ! different attributes of the car class (class = derived type)
                character(len=20) :: model_name
                character(len=20) :: brand
                real :: max_speed
                real :: max_load

                ! a class can also have some procedures (procedures ~ functions) or subroutines assigned to it
                contains
                        procedure, pass(self) :: type_of_car
        end type car

        contains
                ! the definition of the procedure that is assigned to the car class
                subroutine type_of_car(self)
                        class(car), intent(in) :: self
                        
                        if(self%max_speed > 200.00) then
                                print*, "sports car"
                        else
                                print*, "not a sports car"
                        end if
                end subroutine type_of_car
end module mod_car

program DerivedTypeDemo
        use mod_car
        implicit none
        type(car) :: BMW_M8 ! declare a variable of the class car

        ! assign values to the given attributes of the car class
        BMW_M8 % model_name = "M8"
        BMW_M8 % brand = "BMW"
        BMW_M8 % max_speed = 300.00  ! km/h
        BMW_M8 % max_load = 500.00   ! kg
        
        ! call the procedure that is assigned to the car class
        call BMW_M8 % type_of_car()
end program DerivedTypeDemo
