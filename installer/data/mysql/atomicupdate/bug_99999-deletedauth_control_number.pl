use Modern::Perl;
use Koha::Installer::Output qw(say_warning say_success say_info);

return {
    bug_number  => "99999",
    description => "Add new column control_number to deletedauth_header",
    up          => sub {
        my ($args) = @_;
        my ( $dbh, $out ) = @$args{qw(dbh out)};

        if ( !column_exists( 'deletedauth_header', 'control_number' ) ) {

            $dbh->do(
                q{
                ALTER TABLE deletedauth_header
                ADD COLUMN `control_number` varchar(20) DEFAULT NULL AFTER `modification_time`
            }
            );
            $dbh->do(
                q{
                ALTER TABLE deletedauth_header
                ADD UNIQUE KEY `cnumberidx` (`control_number`)
            }
            );

            say_success( $out, "Added column 'deletedauth_header.control_number'" );

        } else {
            say_info(
                $out,
                "Column 'deletedauth_header.control_number' already exists!"
            );
        }
    },
};
