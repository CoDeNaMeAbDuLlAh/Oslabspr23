                                        Summary of Lab 11: Linux Hardening Security and Firewall

Definition: Linux hardening refers to the process of proactively securing a Linux system.

Q; what is squid ? 
Squid is a popular open-source caching and proxy server that runs on Linux
sudo apt-get update
sudo apt-get install squid
sudo Gedit /etc/squi.conf
sudo gedit /etc/squid/blocksite
sudo systemctl restart squid


Basic Linux Hardening Techniques (LHT):

    Disabling unnecessary services and applications.
    Keeping the system up-to-date with security patches and updates.
    Configuring and using a firewall to control network traffic.
    Implementing strong password policies.
    Configuring file system permissions to restrict access to sensitive files and directories.
    Implementing user management best practices, such as limiting user privileges and monitoring user activity.

Linux Hardening Tools:

Here are some basic commands:

    Disabling a service using systemctl: sudo systemctl disable <service-name>.
    Configuring automatic updates: sudo apt-get install unattended-upgrades.
    Choosing a firewall: sudo apt-get install firewalld.
    Downloading and configuring nftables: sudo dpkg -l | grep nftables.

Consider these four things when choosing passwords: length, complexity, age, and history.

Set ownership and group permissions:

    To give ownership of a file named sensitive.txt to a user named "username," run: chown username sensitive.txt.
    To give group ownership of a file named sensitive.txt to a group named "sensitive-group," run: chgrp sensitive-group sensitive.txt.
    To give the user read and write permissions for a file named file.txt, run: chmod u+rw file.txt.
    To give group members read permissions and no permissions to others for a file named file.txt, run: chmod g+r file.txt, chmod o-rwx file.txt.
    To give user "alice" write permissions for a file named sensitive.txt, run: setfacl -m u:alice:rw sensitive.txt.

Implementing User Management:

    Limit user privileges.
    Implement strong password policies.
    Monitor user activity.
    Conduct regular security training.
    Review and audit user accounts.

Hardening tools are software programs that automate this process, making it easier for administrators to identify and eliminate security risks. Examples include JShielder, Lynis, OpenSCAP, Zeus, and nixarmor.



COMPARISON BETWEEN TOOLS ::

   JShielder:

    What it does: JShielder is a Linux hardening script designed to help with securing the Linux server. It performs system hardening and auditing tasks automatically.
    How to effectively use it: JShielder is easy to use, and the user only needs to execute the script with administrative privileges. It will prompt the user with various options to harden the system and implement the selected options.
    Shortcomings: JShielder is a script that relies on the user to choose the hardening options, and it may not cover all possible security risks.
    Alternatives/Competitors: Other Linux hardening tools include Lynis, OpenSCAP, and nixarmor.

    Lynis:

    What it does: Lynis is an open-source security auditing tool designed for Linux and Unix-based systems. It performs system and application security audits, vulnerability scanning, and configuration hardening.
    How to effectively use it: Lynis can be used with a simple command "sudo lynis audit system," and it generates an audit report with the system's security score and possible security risks.
    Shortcomings: Lynis requires administrative privileges to run, and it may generate false positives or false negatives in the audit report.
    Alternatives/Competitors: Alternatives to Lynis include JShielder, OpenVAS, and AIDE.

    OpenSCAP:

    What it does: OpenSCAP (Security Content Automation Protocol) is an open-source framework for system automation and compliance management. It provides a standardized approach for automating security controls and compliance checks.
    How to effectively use it: OpenSCAP provides pre-defined security policies that can be used to scan and evaluate the system's compliance. It also allows users to create custom policies according to their requirements.
    Shortcomings: OpenSCAP requires a thorough understanding of compliance policies and security standards to effectively use it.
    Alternatives/Competitors: Alternatives to OpenSCAP include Lynis, Nessus, and CIS-CAT.
    
    
Conclusion:

In conclusion, Linux hardening is the process of proactively securing a Linux system by implementing various security measures such as disabling unnecessary services, using a firewall, implementing strong passwords, configuring file system permissions, implementing user management best practices, and using hardening tools.



prepared by :Abdullah shaikh ------------------------------------------------------------------------------------------------------- 21k-4783 





Screenshots :
                                                                (SQUID)
                                                                
![ab1](https://user-images.githubusercontent.com/123714247/234627543-122f404e-8bd4-4d4f-b5e7-f6f2f397f766.png)

![ab2](https://user-images.githubusercontent.com/123714247/234627552-91c12ea8-cda5-493f-a518-57b103d0fef5.png)

![ab3](https://user-images.githubusercontent.com/123714247/234627581-d4ec86a5-caf8-46db-9e34-26f1f4c7f5dd.png)

![ab4](https://user-images.githubusercontent.com/123714247/234627599-f3bc9419-c1e1-46fa-94cf-e3572b97f51a.png)



linux hardening screenshots :

![l1](https://user-images.githubusercontent.com/123714247/234642832-f8ca766a-2919-41a4-80bf-ee072032cdda.png)



![l2](https://user-images.githubusercontent.com/123714247/234642861-f65caaae-3fb0-4302-8c39-5977e6e67104.png)

![l3](https://user-images.githubusercontent.com/123714247/234642907-eaeebb8d-046b-407f-843b-62ee6a6ca9e5.png)
![l4](https://user-images.githubusercontent.com/123714247/234642958-fda09659-4e4f-4dad-bfd8-86f108d99bc0.png)


![l5](https://user-images.githubusercontent.com/123714247/234642966-75f5a670-7ec7-4627-9d4e-cd01bfba9bff.png)


![l6](https://user-images.githubusercontent.com/123714247/234643015-9269397e-9d1a-4894-bc90-54419c76e632.png)

![l7](https://user-images.githubusercontent.com/123714247/234643031-b8d78b8b-f2ad-42e6-be5d-3d0d6e83c16b.png)

![l8](https://user-images.githubusercontent.com/123714247/234643047-18aaa9fb-348a-4100-9076-8c44ac287174.png)

![l9](https://user-images.githubusercontent.com/123714247/234643101-e40f4118-769e-4afe-8e85-1aeaaa1a4e75.png)
![l10](https://user-images.githubusercontent.com/123714247/234643107-d4c92575-95fb-40f0-8d74-a5e24f02caf6.png)

![l11](https://user-images.githubusercontent.com/123714247/234643120-4af3a35f-ae1a-42cb-81f9-b85a80b4cb4f.png)

![l12](https://user-images.githubusercontent.com/123714247/234643136-85d21c20-2a07-4680-b30b-09b58f36eb4e.png)
![l13](https://user-images.githubusercontent.com/123714247/234643148-fe274f47-8153-4497-9591-0f09b9b5efda.png)
<img width="493" alt="Capture" src="https://user-images.githubusercontent.com/123714247/234655332-b90ba3d1-8ef6-4e42-93c0-88670aa3841e.PNG">


![l14](https://user-images.githubusercontent.com/123714247/234643160-26ae62a4-ea71-4fa1-a6bf-9c8859ae55e0.png)

![l15](https://user-images.githubusercontent.com/123714247/234643167-92ff3ffa-6f6e-4d32-a0b2-104e86e7d3de.png)




