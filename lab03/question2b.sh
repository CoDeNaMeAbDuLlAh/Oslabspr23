

echo "enter full email "
read e
recipient="$e"
echo "enter subject"
read s
subject="$s"
echo "enter body text"
read b
body="$b"
echo "Name of the file you want to attack in the format abc.txt"
read a
attachment="$a"

# send the email with the attachment
echo "$body" | mutt -s "$subject" -a "$attachment" -- "$recipient"

