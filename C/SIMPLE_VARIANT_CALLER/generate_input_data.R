nucleotides <- c("A", "T", "C", "G")
seq_len <- 1000
n_sequences <- 500

# generate string corresponding to reference sequence (with identifier)
ref_name <- "REF: "
ref_seq <- ""
for(i in 1:seq_len){
    ref_seq <- paste0(ref_seq, sample(nucleotides,1))
}
ref <- paste0(ref_name, ref_seq)

# generate individual strings corresponding to the sequences (with identifiers)
for(i in 1:n_sequences){
    seq_name <- paste0("SEQ",as.character(i), ": ")
    seq <- ""
    for(j in 1:seq_len){
        seq <- paste0(seq, sample(nucleotides,1))
    }
    seq <- paste0(seq_name, seq)
}


# somehow write this to a .txt file which can be the input for the C variant caller