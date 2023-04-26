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






