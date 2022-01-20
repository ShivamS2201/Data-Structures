interface Bank {
    void name(String nBank);

    float ROI();
}

class SBI implements Bank {
    public void name(String SBInBank) {
        System.out.println("SBI Bank - Branch Name: " + SBInBank);
    }

    public float ROI() {
        return 9.15f;
    }
}

class PNB implements Bank {
    public void name(String PNBnBank) {
        System.out.println("PNB Bank - Branch Name: " + PNBnBank);
    }

    public float ROI() {
        return 9.7f;
    }
}

class Caller {
    public static void main(String[] args) {
        Bank b = new SBI(); // an object of SBI has been made which implements the interface BANK.
        Bank p = new PNB();
        System.out.println("------------------------\n");
        p.name("Shalimar Bagh Shakha");
        System.out.println("\nROI given : " + p.ROI());
        System.out.println("\n------------------------\n");
        b.name("Pashchim Shakha");
        System.out.println("\nROI given : " + b.ROI());
        System.out.println("------------------------\n");

    }
}