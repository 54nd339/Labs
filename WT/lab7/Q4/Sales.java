package Marketing;
import General.Employee;
public class Sales extends Employee{
    float tallowance(float basic) {
        float ta = 0.05f * earning(basic);
        return ta;
    }
    public void display(float basic){
        System.out.println("\nEmpId : "+empid);
        System.out.println("Total Earning : "+earning(basic));
        System.out.println("Travel Allowance : "+tallowance(basic));
    }
}