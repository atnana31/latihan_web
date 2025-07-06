<?php
include 'connection.php'; // Include database connection
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Data</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
</head>

<body>
    <div class="container mt-5">
        <h2 class="text-center mb-4">DATA SISWA</h2>
        <!-- Tampilkan pesan sukses atau error -->
        <?php
        if (isset($_GET['pesan'])) {
            if ($_GET['pesan'] == 'hapus-berhasil') {
                echo '<div class="alert alert-success">Data berhasil dihapus!</div>';
            } elseif ($_GET['pesan'] == 'gagal-hapus') {
                echo '<div class="alert alert-danger">Gagal menghapus data: ' . htmlspecialchars($_GET['error']) . '</div>';
            } elseif ($_GET['pesan'] == 'update-berhasil') {
                echo '<div class="alert alert-success">Data berhasil diupdate!</div>';
            } elseif ($_GET['pesan'] == 'update-gagal') {
                echo '<div class="alert alert-danger">Gagal mengupdate data: ' . htmlspecialchars($_GET['error']) . '</div>';
            }
        }
        ?>
        <div class="mb-3">
            <a href="tambah-siswa.php" class="btn btn-primary">TAMBAH DATA</a>
        </div>
        <table class="table table-bordered table-striped">
            <thead class="table-dark">
                <tr>
                    <th>NO.</th>
                    <th>NISN</th>
                    <th>NAMA LENGKAP</th>
                    <th>ALAMAT</th>
                    <th>AKSI</th>
                </tr>
            </thead>
            <tbody>
                <?php
                $query = 'SELECT * FROM tb_siswa';
                $result = mysqli_query($connection, $query);
                if (mysqli_num_rows($result) > 0) {
                    $no = 1;
                    while ($row = mysqli_fetch_assoc($result)) {
                        echo '<tr>';
                        echo '<td>' . $no++ . '</td>';
                        echo '<td>' . htmlspecialchars($row['nisn']) . '</td>';
                        echo '<td>' . htmlspecialchars($row['nama_lengkap']) . '</td>';
                        echo '<td>' . htmlspecialchars($row['alamat']) . '</td>';
                        echo '<td>';
                        echo "<a href='edit-siswa.php?nisn=" . $row['nisn'] . "' class='btn btn-sm btn-warning me-2'>EDIT</a>";
                        echo "<a href='hapus-siswa.php?id_siswa=" . $row['id_siswa'] . "' onclick=\"return confirm('Yakin ingin menghapus siswa ini?')\" class='btn btn-sm btn-danger'>HAPUS</a>";
                        echo '</td>';
                        echo '</tr>';
                    }
                } else {
                    echo "<tr><td colspan='5' class='text-center'>Tidak ada data</td></tr>";
                }
                mysqli_close($connection);
                ?>
            </tbody>
        </table>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
</body>

</html>