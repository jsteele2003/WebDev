#!/usr/bin/perl
use strict; 
use CGI ':standard';

print "Content-type: text/html\n\n";

my $name = param('fullname');
my $username = param('username');
my $password = param('passwd');

sub Error
{
	print "Content-type: text/html\n\n";
	print "The server can't $_[0] the $_[1]: $! \n";
	exit;
}

open (LOG, "<members.csv") || Error('open','file');
my $existing = 0;
my @lines = <LOG>;
for(my $i=0; $i<=$#lines; $i++){
	my @compare = split(' ',$lines[$i]);
	if($compare[1] eq $name){
		$existing = 1;
	}
}
close(LOG);
if($existing == 0){
	open (LOG, ">>members.csv") || Error('open','file');
	print LOG "$name $username $password\n";
	close(LOG);
	print qq(<html><head><title>Congratulations</title></head>);
	print qq(<body><p>Your registration is successful!</p><nav><a href="http://cgi.cs.mcgill.ca/~tweins2/welcome.html">Go Back To Welcome Page</a></nav></body></html>);
}
else{
	print "Error: Username already exists";
	print "Location: http://cgi.cs.mcgill.ca/~tweins2/member.html";
}
exit 0;
